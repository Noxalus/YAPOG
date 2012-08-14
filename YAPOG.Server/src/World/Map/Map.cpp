#include "YAPOG/System/Network/Packet.hpp"

#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/ServerInfoAddObjectVisitor.hpp"

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

  void Map::AddObject (yap::DynamicWorldObject* object)
  {
    AddDynamicObject (object);
  }

  void Map::RemoveObject (yap::DynamicWorldObject* object)
  {
    RemoveDynamicObject (object);
  }

  void Map::RemoveObject (const yap::ID& objectWorldID)
  {
    RemoveDynamicObject (&GetObject (objectWorldID));
  }

  void Map::AddObject (yap::StaticWorldObject* object)
  {
    AddStaticObject (object);
  }

  void Map::RemoveObject (yap::StaticWorldObject* object)
  {
    RemoveStaticObject (object);
  }

  void Map::AddPlayer (Player* player)
  {
    player->AddRelay (this);

    players_.Add (player->GetWorldID (), player);

    AddDynamicObject (player);
  }

  void Map::RemovePlayer (Player* player)
  {
    player->RemoveRelay (this);

    RemoveDynamicObject (player);

    players_.Remove (player->GetWorldID ());
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
      [this] (yap::DynamicWorldObject& sender,
           const yap::ChangeEventArgs<const yap::Vector2&>& args)
      {
        HandleOnObjectVelocityChanged (sender, args.Old, args.Current);
      });

    object->OnStateChanged.AddHandler (
      STATE_CHANGED_SYNCHRONIZATION_HANDLER_NAME,
      [this] (yap::DynamicWorldObject& sender,
           const yap::ChangeEventArgs<const yap::String&>& args)
      {
        HandleOnObjectStateChanged (sender, args.Old, args.Current);
      });

    SendAddObject (*object);
  }

  void Map::HandleRemoveDynamicObject (yap::DynamicWorldObject* object)
  {
    yap::Map::HandleRemoveDynamicObject (object);

    object->OnVelocityChanged.RemoveHandler (
      VELOCITY_CHANGED_SYNCHRONIZATION_HANDLER_NAME);

    object->OnStateChanged.RemoveHandler (
      STATE_CHANGED_SYNCHRONIZATION_HANDLER_NAME);

    SendRemoveObject (*object);
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

    packet.Write (object.GetWorldID ());
    packet.Write (object.GetPosition ());
    packet.Write (state);

    SendPacket (packet);
  }

  void Map::SendAddObject (const yap::DynamicWorldObject& object)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoAddObject);

    ServerInfoAddObjectVisitor addObjectVisitor (packet);
    object.Accept (addObjectVisitor);

    SendPacket (packet);
  }

  void Map::SendRemoveObject (const yap::DynamicWorldObject& object)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoRemoveObject);

    packet.Write (object.GetWorldID ());

    SendPacket (packet);
  }

  void Map::SendLoadObjects (yap::IPacket& packet)
  {
    packet.Write (static_cast<yap::UInt64> (GetDynamicObjects ().Count ()));
    for (const auto& idObjectPair : GetDynamicObjects ())
    {
      ServerInfoAddObjectVisitor addObjectVisitor (packet);
      idObjectPair.second->Accept (addObjectVisitor);
    }
  }
} // namespace yse
