#include "YAPOG/System/Network/Packet.hpp"

#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/System/StringHelper.hpp"
namespace yse
{
  const yap::String Map::VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME =
    "VelocitySync";
  const yap::String Map::STATE_CHANGED_SYNCHRONIZATION_HANDLER_NAME =
    "StateSync";

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

    players_.Add (player->GetWorldID (), player);

    AddDynamicObject (player);

    SendAddPlayer (*player);
  }

  void Map::RemovePlayer (Player* player)
  {
    player->RemoveRelay (this);

    players_.Remove (player->GetWorldID ());

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

    for (auto& it : players_)
      if (!it.second->SendPacket (packet))
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

    object->OnStateChanged.AddHandler (
      STATE_CHANGED_SYNCHRONIZATION_HANDLER_NAME,
      [&] (yap::DynamicWorldObject& sender,
           const yap::ChangeEventArgs<const yap::String&>& args)
      {
        HandleOnObjectStateChanged (sender, args.Old, args.Current);
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
    SendObjectMoveInfo (sender, currentVelocity);
  }

  void Map::HandleOnObjectStateChanged (
    yap::DynamicWorldObject& sender,
    const yap::String& oldState,
    const yap::String& currentState)
  {
    SendUpdateObjectState (sender, currentState);
  }

  void Map::SendObjectMoveInfo (
    const yap::DynamicWorldObject& object,
    const yap::Vector2& velocity)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoObjectMoveInfo);

    yap::DebugLogger::Instance ().LogLine (
      "POSITION: [" + yap::StringHelper::ToString (object.GetPosition ().x) +
      "][" + yap::StringHelper::ToString (object.GetPosition ().y) + "]");
    yap::DebugLogger::Instance ().LogLine (
      "VELOCITY: [" + yap::StringHelper::ToString (velocity.x) +
      "][" + yap::StringHelper::ToString (velocity.y) + "]");

    packet.Write (object.GetWorldID ());
    packet.Write (object.GetPosition ());
    packet.Write (velocity);

    SendPacket (packet);
  }

  void Map::SendUpdateObjectState (
    const yap::DynamicWorldObject& object,
    const yap::String& state)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoUpdateObjectState);

    yap::DebugLogger::Instance ().LogLine (
      "POSITION: [" + yap::StringHelper::ToString (object.GetPosition ().x) +
      "][" + yap::StringHelper::ToString (object.GetPosition ().y) + "]");
    yap::DebugLogger::Instance ().LogLine (
      "STATE: [" + state + "]");

    packet.Write (object.GetWorldID ());
    packet.Write (object.GetPosition ());
    packet.Write (state);

    SendPacket (packet);
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
    packet.Write (object.GetPosition ());
//    addPlayerPacket.Write (player.GetState ());
//    addPlayerPacket.Write (player.GetDirection ());
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

    SendPacket (addPlayerPacket);
  }

  void Map::SendRemovePlayer (const Player& player)
  {
    yap::Packet removePlayerPacket;
    removePlayerPacket.CreateFromType (
      yap::PacketType::ServerInfoRemovePlayer);

    removePlayerPacket.Write (player.GetWorldID ());

    SendPacket (removePlayerPacket);
  }

  void Map::SendLoadObjects (yap::IPacket& packet)
  {
    // players
    packet.Write (static_cast<yap::UInt64> (players_.Count ()));

    for (const auto& it : players_)
      SendAddObject (*it.second, packet);
  }
} // namespace yse
