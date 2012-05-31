#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"

#include "Client/User.hpp"
#include "World/World.hpp"
#include "World//Map/Map.hpp"
#include "World/Map/Player.hpp"

namespace ycl
{
  User::User ()
    : packetHandler_ ()
    , world_ (nullptr)
    , playerWorldID_ ()
    , player_ (nullptr)
  {
    ADD_HANDLER(ServerInfoStartInfo, User::HandleServerInfoStartInfo);
    ADD_HANDLER(ServerInfoChangeMap, User::HandleServerInfoChangeMap);
    ADD_HANDLER(ServerInfoAddObject, User::HandleServerInfoAddObject);
    ADD_HANDLER(ServerInfoAddPlayer, User::HandleServerInfoAddPlayer);
//    ADD_HANDLER(ServerInfoMoveInfo, User::HandleServerInfoMoveInfo);
  }

  User::~User ()
  {
  }

  void User::SetWorld (World* world)
  {
    world_ = world;
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
    player_ = player;

    AddRelay (player_);
    player_->SetParent (this);

    yap::PhysicsCore* physicsCore = new yap::BasicPhysicsCore ();
    physicsCore->SetVelocityBounds (
      yap::Vector2 (),
      player_->GetMaxVelocity ());
    player_->SetPhysicsCore (physicsCore);

    OnPlayerCreated (*this, player_);
  }

  void User::HandleServerInfoStartInfo (yap::IPacket& packet)
  {
    /// @todo

    playerWorldID_ = packet.ReadID ();
  }

  void User::HandleServerInfoChangeMap (yap::IPacket& packet)
  {
    yap::ID mapWorldID = packet.ReadID ();
    yap::ID mapID = packet.ReadID ();

    world_->AddMap (mapWorldID, mapID);
    world_->ChangeMap (mapWorldID);
  }

  void User::HandleServerInfoAddObject (yap::IPacket& packet)
  {
  }

  void User::HandleServerInfoAddPlayer (yap::IPacket& packet)
  {
    yap::ID worldID = packet.ReadID ();
    yap::ID typeID = packet.ReadID ();
    yap::ID id = packet.ReadID ();

    Player* player = yap::ObjectFactory::Instance ().Create<Player> (
      typeID,
      id);
    player->SetWorldID (worldID);

    if (playerWorldID_ == player->GetWorldID ())
      SetPlayer (player);

    world_->GetCurrentMap ().AddPlayer (player);

    player->SetPosition (packet.ReadVector2 ());
  }
} // namespace ycl
