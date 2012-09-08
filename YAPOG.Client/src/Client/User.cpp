#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/RectReader.hpp"
#include "YAPOG/Game/Chat/GameMessage.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/Game/Pokemon/PokemonMove.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"

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
    , id_ (0)
    , world_ (nullptr)
    , player_ (nullptr)
    , playerData_ ()
    , trainer_ (nullptr)
  {
    ADD_HANDLER(ServerInfoSetUserPlayer, User::HandleServerInfoSetUserPlayer);
    ADD_HANDLER(ServerInfoChangeMap, User::HandleServerInfoChangeMap);
    ADD_HANDLER(ServerInfoAddObject, User::HandleServerInfoAddObject);
    ADD_HANDLER(ServerInfoRemoveObject, User::HandleServerInfoRemoveObject);
    ADD_HANDLER(ServerInfoGameMessage, User::HandleServerInfoGameMessage);
    ADD_HANDLER(ServerInfoTriggerBattle, User::HandleServerInfoTriggerBattle);
    ADD_HANDLER(ServerInfoPokemonTeam, User::HandlerServerInfoPokemonTeam);
    ADD_HANDLER(ServerInfoChangeMoney, User::HandlerServerInfoChangeMoney);
  }

  User::~User ()
  {
  }

  PlayerTrainer& User::GetTrainer () const
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

  const yap::ID& User::GetID () const
  {
    return id_;
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

  void User::ChangeMoney (int value)
  {
    playerData_.ChangeMoney (value);
  }

  void User::UpdatePlayTime (const yap::Time& dt)
  {
    playerData_.UpdatePlayTime (dt);
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

  const PlayerData& User::GetPlayerData () const
  {
    return playerData_;
  }

  // Setters.
  void User::SetPlayer (Player* player)
  {
    player_ = player;

    OnPlayerCreated (*this, player_);
  }

  void User::HandleServerInfoSetUserPlayer (yap::IPacket& packet)
  {
    yap::ID accountID = packet.ReadID ();
    yap::ID playerWorldID = packet.ReadID ();

    id_ = accountID;

    Player* player =
      &GetWorld ().GetCurrentMap ().GetPlayer (playerWorldID);

    SetPlayer (player);

    // Get player's data
    yap::UInt32 money = packet.ReadUInt ();
    yap::UInt32 playTime = packet.ReadUInt ();

    playerData_.RawSetMoney (money);
    playerData_.RawSetPlayTime (yap::Time (playTime));

    OnPlayerDataReceived (*this, yap::EmptyEventArgs ());
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

  /// @warning [TEMPORARY]
  /// @todo use dedicated visitors
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

        player->RawSetDirection (
          static_cast<yap::Direction> (
          packet.ReadUChar ()));

        packet.ReadString (); // name is read
      }
      else
      {
        player = yap::ObjectFactory::Instance ().Create<Player> (
          typeID,
          id);

        player->SetWorldID (worldID);

        player->RawSetDirection (
          static_cast<yap::Direction> (
          packet.ReadUChar ()));

        yap::String playerName = packet.ReadString ();
        player->SetName (playerName);
      }

      object = player;

      map.AddPlayer (player);
    }
    if (objectTypeName == "NPC")
    {
      NPC* npc = yap::ObjectFactory::Instance ().Create<NPC> (typeID, id);
      object = npc;
      npc->SetWorldID (worldID);

      npc->RawSetDirection (
        static_cast<yap::Direction> (
        packet.ReadUChar ()));

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
      yap::ID staticID = packet.ReadID ();
      yap::ID uniqueID = packet.ReadID ();
      yap::Gender gender =
        static_cast<yap::Gender>(packet.ReadUChar ());
      yap::PokemonStatus status =
        static_cast<yap::PokemonStatus>(packet.ReadUChar ());
      yap::String nickname = packet.ReadString ();
      bool shiny = packet.ReadBool ();
      yap::Int16 loyalty = packet.ReadInt16 ();
      yap::ID nature = packet.ReadID ();
      yap::uint experience = packet.ReadUInt ();
      yap::UInt8 boxNumber = packet.ReadUChar ();
      yap::ID boxIndex = packet.ReadID ();
      yap::String catchDate = packet.ReadString ();
      yap::UInt16 currentHP = packet.ReadUInt16 ();

      // Read the Pokemon's EV value
      yap::UInt16 hpEV = packet.ReadUInt16 ();
      yap::UInt16 attackEV = packet.ReadUInt16 ();
      yap::UInt16 defenseEV = packet.ReadUInt16 ();
      yap::UInt16 specialAttackEV = packet.ReadUInt16 ();
      yap::UInt16 specialDefenseEV = packet.ReadUInt16 ();
      yap::UInt16 speedEV = packet.ReadUInt16 ();

      // Read the Pokemon's IV value
      yap::UInt16 hpIV = packet.ReadUInt16 ();
      yap::UInt16 attackIV = packet.ReadUInt16 ();
      yap::UInt16 defenseIV = packet.ReadUInt16 ();
      yap::UInt16 specialAttackIV = packet.ReadUInt16 ();
      yap::UInt16 specialDefenseIV = packet.ReadUInt16 ();
      yap::UInt16 speedIV = packet.ReadUInt16 ();

      // Set the stats with EV and IV
      yap::HitPoint hp (currentHP, hpEV, hpIV);
      yap::Attack attack (attackEV, attackIV);
      yap::Defense defense (defenseEV, defenseIV);
      yap::SpecialAttack specialAttack (specialAttackEV, specialAttackIV);
      yap::SpecialDefense specialDefense (specialDefenseEV, specialDefenseIV);
      yap::Speed speed (speedEV, speedIV);

      yap::PokemonStat stats (
        hp,
        attack,
        defense,
        specialAttack,
        specialDefense,
        speed);

      // Read the Pokemon's move
      yap::PokemonMoveSet moveSet;
      yap::UInt8 moveNumber = packet.ReadUChar ();

      for (int index = 0; index < moveNumber; index++)
      {
        yap::PokemonMove* move = new yap::PokemonMove (packet.ReadID ());
        yap::UInt8 moveIndex = packet.ReadUChar ();

        move->SetPP (packet.ReadUInt16 ());
        move->SetMaxPP (packet.ReadUInt16 ());

        moveSet.AddMove (move, moveIndex);
      }

      Pokemon* currentPokemon = new Pokemon (
        uniqueID,
        staticID,
        login_,
        nickname,
        stats,
        gender,
        status,
        shiny,
        loyalty,
        moveSet,
        nature,
        experience,
        boxNumber,
        boxIndex,
        catchDate);

      pokemonTeam->AddPokemon (currentPokemon);
    }

    trainer_->SetTeam (pokemonTeam);

    OnPokemonTeamReceived (*this, yap::EmptyEventArgs ());
  }

  void User::HandlerServerInfoChangeMoney (yap::IPacket& packet)
  {
    int amount = packet.ReadInt ();

    ChangeMoney (amount);
  }

} // namespace ycl
