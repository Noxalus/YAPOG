#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Chat/GameMessage.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"

#include "Server/User.hpp"
#include "World/World.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/DynamicObjectFactory.hpp"
#include "Account/AccountManager.hpp"
#include "Account/Account.hpp"
#include "Account/PlayerData.hpp"
#include "Pokemon/PokemonTeam.hpp"

namespace yse
{
  User::User ()
    : packetHandler_ ()
    , login_ ()
    , world_ (nullptr)
    , map_ (nullptr)
    , player_ (nullptr)
    , account_ (nullptr)
  {
    ADD_HANDLER(ClientRequestStartInfo, User::HandleClientRequestStartInfo);
    ADD_HANDLER(ClientInfoApplyForce, User::HandleClientInfoApplyForce);
    ADD_HANDLER(ClientInfoGameMessage, User::HandleClientInfoGameMessage);
  }

  User::~User ()
  {
  }

  void User::SaveAccountData ()
  {
    account_->SaveAccountData (*databaseManager_);
  }

  void User::SetWorld (World* world)
  {
    world_ = world;
  }

  void User::RemoveFromWorld ()
  {
    GetMap ().RemovePlayer (player_);
  }

  const yap::String& User::GetLogin () const
  {
    return login_;
  }

  bool User::Login (
    const yap::String& login,
    const yap::String& password,
    const yap::String& ip)
  {
    login_ = login;

    AccountManager am (*databaseManager_);
    account_ = am.Login (login, password, ip);

    return true;
  }

  bool User::Register (
    const yap::String& login,
    const yap::String& password,
    const yap::String& email,
    const yap::String& ip)
  {
    login_ = login;

    AccountManager am (*databaseManager_);
    return am.CreateNewAccount (login, password, email, ip);

    return true;
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

  World& User::GetWorld ()
  {
    return *world_;
  }

  Map& User::GetMap ()
  {
    return *map_;
  }

  Account& User::GetAccount ()
  {
    return *account_;
  }

  const Player& User::GetPlayer () const
  {
    return *player_;
  }

  void User::SetMap (Map* map)
  {
    map_ = map;

    SendChangeMap (GetMap ());

    GetMap ().AddPlayer (player_);
  }

  void User::ChangeMap (
    const yap::ID& mapWorldID,
    const yap::Vector2& mapPoint)
  {
    if (GetMap ().GetWorldID () != mapWorldID)
    {
      GetMap ().RemovePlayer (player_);

      player_->SetPosition (mapPoint);

      SetMap (&GetWorld ().GetMap (mapWorldID));

      return;
    }

    player_->SetPosition (mapPoint);
  }

  void User::SetPlayer (Player* player)
  {
    if (player == nullptr)
      YAPOG_THROW("argument `player' is null.");

    player_ = player;

    player_->SetParentUser (this);

    AddRelay (player_);
    player_->SetParent (this);

    player_->SetName (login_);
  }

  void User::SetDatabaseManager (yap::DatabaseManager* databaseManager)
  {
    databaseManager_ = databaseManager;
  }

  void User::HandleClientRequestStartInfo (yap::IPacket& packet)
  {
    /// @todo load user info from DB from its login
    /// player guid, player map, player position...
    /// pokemon info...

    /// @todo Reach from DB
    yap::ID playerID = yap::ID (1);

    //yap::ID playerMapWorldID = yap::ID (1);

    yap::ID playerMapWorldID =
      account_->GetPlayerData ().GetMapID ();

    SetPlayer (
      DynamicObjectFactory::Instance ().Create<Player> (
      "Player",
      playerID));

    // Get the actual position from the database
    player_->SetPosition (
      account_->GetPlayerData ().GetPosition ());

    SetMap (&world_->GetMap (playerMapWorldID));

    yap::Packet setUserPlayerPacket;
    setUserPlayerPacket.CreateFromType (
      yap::PacketType::ServerInfoSetUserPlayer);

    setUserPlayerPacket.Write (account_->GetID ());
    setUserPlayerPacket.Write (player_->GetWorldID ());

    // Write player's data here
    setUserPlayerPacket.Write (account_->GetPlayerData ().GetMoney ());
    setUserPlayerPacket.Write (account_->GetPlayerData ().GetPlayTime ().GetValue ());

    SendPokemonTeam (account_->GetTeam ());

    SendPacket (setUserPlayerPacket);
  }

  void User::HandleClientInfoApplyForce (yap::IPacket& packet)
  {
    yap::Vector2 force = packet.ReadVector2 ();

    player_->ApplyForce (force);
  }

  void User::SendChangeMap (Map& map)
  {
    yap::Packet changeMapPacket;
    changeMapPacket.CreateFromType (yap::PacketType::ServerInfoChangeMap);

    changeMapPacket.Write (map.GetWorldID ());
    changeMapPacket.Write (map.GetID ());

    map.SendLoadObjects (changeMapPacket);

    SendPacket (changeMapPacket);
  }

  void User::HandleClientInfoGameMessage (yap::IPacket& packet)
  {
    yap::String senderName = packet.ReadString ();
    yap::String content = packet.ReadString ();

    yap::GameMessage gameMessage;
    gameMessage.SetSenderName (senderName);
    gameMessage.SetContent (content);

    SendGameMessage (gameMessage);
  }

  void User::SendGameMessage (const yap::GameMessage& message)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoGameMessage);

    packet.Write (message.GetSenderName ());
    packet.Write (message.GetContent ());

    GetWorld ().SendPacket (packet);
  }

  void User::SendPokemonTeam (PokemonTeam& pokemonTeam)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoPokemonTeam);

    // Send the number of Pokemon in the team
    int pokemonNumber = pokemonTeam.GetPokemonCount ();
    packet.Write (pokemonNumber);

    Pokemon* currentPokemon = nullptr;

    for (int i = 0; i < pokemonNumber; i++)
    {
      currentPokemon = &pokemonTeam.GetPokemon (i);

      // Write the current pokemon basic information in the packet
      packet.Write (currentPokemon->GetStaticID ());
      packet.Write (currentPokemon->GetUniqueID ());
      packet.Write (static_cast<yap::UInt8>(currentPokemon->GetGender ()));
      packet.Write (static_cast<yap::UInt8>(currentPokemon->GetStatus ()));
      packet.Write (currentPokemon->GetNickname ());
      packet.Write (currentPokemon->GetShiny ());
      packet.Write (currentPokemon->GetLoyalty ());
      packet.Write (currentPokemon->GetNatureID ());
      packet.Write (currentPokemon->GetTotalExperience ());
      packet.Write (currentPokemon->GetBoxNumber ());
      packet.Write (currentPokemon->GetBoxIndex ());
      packet.Write (currentPokemon->GetCatchDate ());
      packet.Write (currentPokemon->GetCurrentHP ());

      // Write the current Pokemon's stats
      const yap::PokemonStat& stats = currentPokemon->GetStats ();

      // Send EV
      packet.Write (stats.GetHitPoint ().GetEffortValue ());
      packet.Write (stats.GetAttack ().GetEffortValue ());
      packet.Write (stats.GetDefense ().GetEffortValue ());
      packet.Write (stats.GetSpecialAttack ().GetEffortValue ());
      packet.Write (stats.GetSpecialDefense ().GetEffortValue ());
      packet.Write (stats.GetSpeed ().GetEffortValue ());

      // Send IV
      packet.Write (stats.GetHitPoint ().GetIndividualValue ());
      packet.Write (stats.GetAttack ().GetIndividualValue ());
      packet.Write (stats.GetDefense ().GetIndividualValue ());
      packet.Write (stats.GetSpecialAttack ().GetIndividualValue ());
      packet.Write (stats.GetSpecialDefense ().GetIndividualValue ());
      packet.Write (stats.GetSpeed ().GetIndividualValue ());

      // Send Pokemon's moves
      const yap::PokemonMoveSet& moveSet =
        currentPokemon->GetMoveSet ();
      yap::UInt8 moveNumber = currentPokemon->GetMoveSet ().GetMoveNumber ();

      // Send the move number of the Pokemon
      packet.Write (moveNumber);

      for (yap::UInt8 index = 0; index < 4; index++)
      {
        if (moveSet.GetMove (index) != nullptr)
        {
          packet.Write (moveSet.GetMove (index)->GetStaticID ());
          packet.Write (index);
          packet.Write (moveSet.GetMove (index)->GetCurrentPP ());
          packet.Write (moveSet.GetMove (index)->GetMaxPP ());
        }
      }

    }

    SendPacket (packet);
  }

  void User::SendChangeMoney (int value)
  {
    // Change the money of player in the server
    account_->ChangeMoney (value);

    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoChangeMoney);

    packet.Write (value);

    SendPacket (packet);
  }

} // namespace yse
