#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/RectReader.hpp"
#include "YAPOG/Game/Chat/GameMessage.hpp"
#include "YAPOG/System/Network/Packet.hpp"

#include "Client/User.hpp"
#include "World/World.hpp"
#include "World//Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/NPC.hpp"
#include "World/Map/OpenBattleSpawnerArea.hpp"
#include "World/Map/Teleporter.hpp"
#include "World/Map/DestructibleObject.hpp"
#include "Battle/PlayerTrainer.hpp"
#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"

namespace ycl
{
  User::User ()
    : packetHandler_ ()
    , login_ ()
    , world_ (nullptr)
    , player_ (nullptr)
    , trainer_ (nullptr)
  {
    ADD_HANDLER(ServerInfoSetUserPlayer, User::HandleServerInfoSetUserPlayer);
    ADD_HANDLER(ServerInfoChangeMap, User::HandleServerInfoChangeMap);
    ADD_HANDLER(ServerInfoAddObject, User::HandleServerInfoAddObject);
    ADD_HANDLER(ServerInfoRemoveObject, User::HandleServerInfoRemoveObject);
    ADD_HANDLER(ServerInfoGameMessage, User::HandleServerInfoGameMessage);
    ADD_HANDLER(ServerInfoTriggerBattle, User::HandleServerInfoTriggerBattle);
    ADD_HANDLER(ServerInfoPokemonTeam, User::HandlerServerInfoPokemonTeam);
  }

  User::~User ()
  {
  }

  PlayerTrainer& User::GetTrainer ()
  {
    return *trainer_;
  }

  void User::SetTrainer (PlayerTrainer* trainer)
  {
    trainer_ = trainer;
  }

  const yap::String& User::GetLogin () const
  {
    return login_;
  }

  void User::SetLogin (const yap::String& login)
  {
    login_ = login;
  }

  void User::SetWorld (World* world)
  {
    world_ = world;

    AddRelay (world_);
    world_->SetParent (this);
  }

  void User::SendGameMessage (const yap::GameMessage& message)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoGameMessage);

    packet.Write (message.GetSenderName ());
    packet.Write (message.GetContent ());

    SendPacket (packet);
  }

  bool User::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool User::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void User::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void User::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void User::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  // Getters.
  World& User::GetWorld ()
  {
    return *world_;
  }

  Map& User::GetMap ()
  {
    return GetWorld ().GetCurrentMap ();
  }

  Player& User::GetPlayer ()
  {
    return *player_;
  }

  // Setters.
  void User::SetPlayer (Player* player)
  {
    player_ = player;

    OnPlayerCreated (*this, player_);
  }

  void User::HandleServerInfoSetUserPlayer (yap::IPacket& packet)
  {
    yap::ID playerWorldID = packet.ReadID ();

    Player* player =
      &GetWorld ().GetCurrentMap ().GetPlayer (playerWorldID);

    SetPlayer (player);
  }

  void User::HandleServerInfoChangeMap (yap::IPacket& packet)
  {
    yap::ID mapWorldID = packet.ReadID ();
    yap::ID mapID = packet.ReadID ();

    world_->AddMap (mapWorldID, mapID);
    world_->ChangeMap (mapWorldID);

    GetMap ().ClearDynamicObjects ();

    yap::UInt64 objectCount = packet.ReadUInt64 ();
    for (yap::UInt64 count = 0; count < objectCount; ++count)
    {
      HandleServerInfoAddObject (packet);
    }
  }

  void User::HandleServerInfoAddObject (yap::IPacket& packet)
  {
    yap::ID worldID = packet.ReadID ();
    yap::ID typeID = packet.ReadID ();
    yap::ID id = packet.ReadID ();

    yap::Vector2 position = packet.ReadVector2 ();
    yap::String state = packet.ReadString ();

    const yap::String& objectTypeName =
      yap::ObjectFactory::Instance ().GetType (typeID);

    yap::DynamicWorldObject* object = nullptr;

    Map& map = GetMap ();

    bool playerIsWarped = false;

    if (objectTypeName == "Player")
    {
      Player* player = nullptr;

      if (player_ != nullptr && GetPlayer ().GetWorldID () == worldID)
      {
        player = player_;
        playerIsWarped = true;
      }
      else
      {
        player = yap::ObjectFactory::Instance ().Create<Player> (
          typeID,
          id);

        player->SetWorldID (worldID);
      }

      object = player;

      map.AddPlayer (player);
    }
    if (objectTypeName == "NPC")
    {
      NPC* npc = yap::ObjectFactory::Instance ().Create<NPC> (typeID, id);
      object = npc;
      npc->SetWorldID (worldID);

      map.AddDrawableDynamicObject (npc);
    }
    if (objectTypeName == "Teleporter")
    {
      Teleporter* teleporter =
        yap::ObjectFactory::Instance ().Create<Teleporter> (typeID, id);
      object = teleporter;
      teleporter->SetWorldID (worldID);

      yap::ID mapWorldID = packet.ReadID ();
      yap::Vector2 mapPoint = packet.ReadVector2 ();
      yap::FloatRect area;
      yap::RectReader<float> rectReader (area);
      packet.Accept (rectReader);

      teleporter->Init (mapWorldID, mapPoint, area);
      map.AddDrawableDynamicObject (teleporter);
    }
    if (objectTypeName == "DestructibleObject")
    {
      DestructibleObject* destructibleObject =
        yap::ObjectFactory::Instance ().Create<DestructibleObject> (
        typeID,
        id);
      object = destructibleObject;
      destructibleObject->SetWorldID (worldID);

      map.AddDrawableDynamicObject (destructibleObject);
    }
    if (objectTypeName == "OpenBattleSpawnerArea")
    {
      OpenBattleSpawnerArea* openBattleSpawnerArea =
        yap::ObjectFactory::Instance ().Create<OpenBattleSpawnerArea> (
        typeID,
        id);

      object = openBattleSpawnerArea;
      openBattleSpawnerArea->SetWorldID (worldID);

      yap::uint width = packet.ReadUInt ();
      yap::uint height = packet.ReadUInt ();
      openBattleSpawnerArea->InitArea (width, height);

      map.AddDrawableDynamicObject (openBattleSpawnerArea);
    }

    object->SetPosition (position);
    object->RawSetState (state);

    if (playerIsWarped)
      OnPlayerWarped (*this, *player_);
  }

  void User::HandleServerInfoRemoveObject (yap::IPacket& packet)
  {
    yap::ID worldID = packet.ReadID ();

    Map& map = GetMap ();

    if (map.ContainsPlayer (worldID))
    {
      map.RemovePlayer (worldID);
      return;
    }

    map.RemoveDrawableDynamicObject (worldID);
  }

  void User::HandleServerInfoGameMessage (yap::IPacket& packet)
  {
    yap::String senderName = packet.ReadString ();
    yap::String content = packet.ReadString ();

    yap::GameMessage gameMessage;
    gameMessage.SetSenderName (senderName);
    gameMessage.SetContent (content);

    OnMessageReceived (*this, gameMessage);
  }

  void User::HandleServerInfoTriggerBattle (yap::IPacket& packet)
  {
    OnBattleTriggered (*this, yap::EmptyEventArgs ());
  }

  void User::HandlerServerInfoPokemonTeam (yap::IPacket& packet)
  {
    PokemonTeam* pokemonTeam = new PokemonTeam ();

    trainer_ = new PlayerTrainer ();

    int pokemonCount = packet.ReadInt ();

    for (int i = 0; i < pokemonCount; i++)
    {
      Pokemon* currentPokemon = new Pokemon (packet.ReadID ());

      currentPokemon->SetUniqueID (packet.ReadID ());
      currentPokemon->SetExperience (packet.ReadUInt ());
      currentPokemon->SetGender (packet.ReadUChar ());
      currentPokemon->SetNickname (packet.ReadString ());
      currentPokemon->SetLevel (packet.ReadUInt16 ());
      currentPokemon->SetShiny (packet.ReadBool ());
      currentPokemon->SetLoyalty (packet.ReadInt ());
      currentPokemon->SetNature (packet.ReadID ());

      pokemonTeam->AddPokemon (currentPokemon);
    }

    trainer_->SetTeam (pokemonTeam);

    OnPokemonTeamReceived (*this, yap::EmptyEventArgs ());
  }

} // namespace ycl
