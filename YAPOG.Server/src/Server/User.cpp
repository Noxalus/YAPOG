#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Chat/GameMessage.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"

#include "Server/User.hpp"
#include "World/World.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/DynamicObjectFactory.hpp"
#include "Account/AccountManager.hpp"


namespace yse
{
  User::User ()
    : packetHandler_ ()
    , login_ ()
    , world_ (nullptr)
    , map_ (nullptr)
    , player_ (nullptr)
  {
    ADD_HANDLER(ClientRequestStartInfo, User::HandleClientRequestStartInfo);
    ADD_HANDLER(ClientInfoApplyForce, User::HandleClientInfoApplyForce);
    ADD_HANDLER(ClientInfoGameMessage, User::HandleClientInfoGameMessage);
  }

  User::~User ()
  {
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

    /*
    AccountManager am;
    am.Login (login, password, ip);
    */

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
  }

  void User::HandleClientRequestStartInfo (yap::IPacket& packet)
  {
    /// @todo load user info from DB from its login
    /// player guid, player map, player position...
    /// pokemon info...

    /// @todo Reach from DB
    yap::ID playerID = yap::ID (1);
    yap::ID playerMapWorldID = yap::ID (1);

    SetPlayer (
      DynamicObjectFactory::Instance ().Create<Player> (
        "Player",
        playerID));

    SetMap (&world_->GetMap (playerMapWorldID));

    yap::Packet setUserPlayerPacket;
    setUserPlayerPacket.CreateFromType (
      yap::PacketType::ServerInfoSetUserPlayer);

    setUserPlayerPacket.Write (player_->GetWorldID ());

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
} // namespace yse
