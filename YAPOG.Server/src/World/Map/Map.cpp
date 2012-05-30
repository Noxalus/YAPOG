#include "YAPOG/System/Network/Packet.hpp"

#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"

namespace yse
{
  const yap::String Map::VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME =
    "Sync";

  Map::Map (const yap::ID& id)
    : yap::Map (id)
    , players_ ()
    , packetHandler_ ()
  {
  }

  Map::~Map ()
  {
  }

  void Map::AddPlayer (Player* player)
  {
    player->AddRelay (this);

    players_.Add (player);
    AddDynamicObject (player);

    SendAddPlayer (*player);
  }

  void Map::RemovePlayer (Player* player)
  {
    player->RemoveRelay (this);

    players_.Remove (player);
    RemoveDynamicObject (player);

    SendRemovePlayer (*player);
  }

  bool Map::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Map::SendPacket (yap::IPacket& packet)
  {
    bool success = true;

    for (Player* player : players_)
      if (!player->SendPacket (packet))
        success = false;

    return success;
  }

  void Map::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void Map::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void Map::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }

  void Map::HandleAddDynamicObject (yap::DynamicWorldObject* object)
  {
    yap::Map::HandleAddDynamicObject (object);

    object->OnVelocityChanged.AddHandler (
      VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME,
      [&] (yap::DynamicWorldObject& sender,
           const yap::ChangeEventArgs<const yap::Vector2&>& args)
    {
      HandleOnObjectVelocityChanged (sender, args.Old, args.Current);
    });
  }

  void Map::HandleRemoveDynamicObject (yap::DynamicWorldObject* object)
  {
    yap::Map::HandleRemoveDynamicObject (object);

    object->OnVelocityChanged.RemoveHandler (
      VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME);
  }

  void Map::HandleOnObjectVelocityChanged (
    yap::DynamicWorldObject& sender,
    const yap::Vector2& oldVelocity,
    const yap::Vector2& currentVelocity)
  {
  }

  /// @todo Write state/direction
  void Map::SendAddObject (
    const yap::DynamicWorldObject& object,
    yap::IPacket& packet)
  {
    packet.Write (object.GetWorldID ());
    packet.Write (object.GetTypeID ());
    packet.Write (object.GetID ());

    /// @todo To send position, tmp
    packet.Write (
      /*player.GetPosition ()*/yap::Vector2 (100.0f, 100.0f));
//    addPlayerPacket.Write (player.GetState ());
//    addPlayerPacket.Write (player.GetDirection ());

    SendPacket (packet);
  }

  void Map::SendRemoveObject (
    const yap::DynamicWorldObject& object,
    yap::IPacket& packet)
  {

  }

  /// @todo Note: [future] add `AddObject (yap::DynamicWorldObject* object)'
  /// public method for adding every type of dyn object except player.
  /// (idem for static)
  void Map::SendAddPlayer (const Player& player)
  {
    yap::Packet addPlayerPacket;
    addPlayerPacket.CreateFromType (yap::PacketType::ServerInfoAddPlayer);

    SendAddObject (player, addPlayerPacket);
  }

  void Map::SendRemovePlayer (const Player& player)
  {
    yap::Packet removePlayerPacket;
    removePlayerPacket.CreateFromType (
      yap::PacketType::ServerInfoRemovePlayer);

    removePlayerPacket.Write (player.GetWorldID ());

    SendPacket (removePlayerPacket);
  }
} // namespace yse
