#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"

#include "Client/User.hpp"
#include "World/World.hpp"
#include "World//Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "Battle/PlayerTrainer.hpp"

namespace ycl
{
  User::User ()
    : packetHandler_ ()
    , world_ (nullptr)
    , player_ (nullptr)
    , trainer_ (nullptr)
  {
    ADD_HANDLER(ServerInfoSetUserPlayer, User::HandleServerInfoSetUserPlayer);
    ADD_HANDLER(ServerInfoChangeMap, User::HandleServerInfoChangeMap);
  }

  User::~User ()
  {
  }

  void User::SetWorld (World* world)
  {
    world_ = world;

    AddRelay (world_);
    world_->SetParent (this);
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

  void User::SetTrainer (PlayerTrainer* trainer)
  {
    trainer_ = trainer;
  }

  void User::HandleServerInfoSetUserPlayer (yap::IPacket& packet)
  {
    /// @todo
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

    Map& map = world_->GetCurrentMap ();
    map.HandleLoadObjects (packet);
  }
} // namespace ycl
