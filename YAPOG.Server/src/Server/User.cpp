#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

#include "Server/User.hpp"
#include "World/World.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"

namespace yse
{
  User::User ()
    : packetHandler_ ()
    , login_ ()
    , player_ (nullptr)
  {
    ADD_HANDLER(ClientRequestStartInfo, User::HandleClientRequestStartInfo);
  }

  User::~User ()
  {
  }

  void User::SetWorld (World* world)
  {
    world_ = world;
  }

  const yap::String& User::GetLogin () const
  {
    return login_;
  }

  bool User::Login (const yap::String& login)
  {
    login_ = login;

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

  void User::SetPlayer (Player* player)
  {
    if (player == nullptr)
      YAPOG_THROW("argument `player' is null.");

    player_ = player;

    AddRelay (player_);
    player_->SetParent (this);
  }

  // tmp
  static int currentID = 0;
  void User::HandleClientRequestStartInfo (yap::IPacket& packet)
  {
    /// @todo load user info from DB from its login
    /// player guid, player map, player position...
    /// pokemon info...

    /// @todo Reach from DB
    yap::ID playerID = yap::ID (1);
    yap::ID playerWorldID = yap::ID (currentID++);
    yap::ID playerMapWorldID = yap::ID (1);

    SetPlayer (
      yap::ObjectFactory::Instance ().Create<Player> (
        "Player",
        playerID));

    player_->SetWorldID (playerWorldID);

    yap::Packet startInfoPacket;
    startInfoPacket.CreateFromType (yap::PacketType::ServerInfoStartInfo);
    startInfoPacket.Write (player_->GetWorldID ());
    SendPacket (startInfoPacket);

    SendChangeMap (world_->GetMap (playerMapWorldID));

    world_->GetMap (playerMapWorldID).AddPlayer (player_);
  }

  void User::SendChangeMap (Map& map)
  {
    yap::Packet changeMapPacket;
    changeMapPacket.CreateFromType (yap::PacketType::ServerInfoChangeMap);

    changeMapPacket.Write (map.GetWorldID ());
    changeMapPacket.Write (map.GetID ());

    /// @todo Send dynamic objects.

    SendPacket (changeMapPacket);
  }
} // namespace yse
