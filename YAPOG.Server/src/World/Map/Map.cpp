#include "YAPOG/System/Network/Packet.hpp"

#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"

namespace yse
{
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

    SendAddPlayer (player);
  }

  void Map::RemovePlayer (Player* player)
  {
    player->RemoveRelay (this);

    players_.Remove (player);
    RemoveDynamicObject (player);

    SendRemovePlayer (player);
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

  void Map::SendAddPlayer (Player* player)
  {
    yap::Packet addPlayerPacket;
    addPlayerPacket.CreateFromType (yap::PacketType::ServerInfoAddPlayer);

    addPlayerPacket.Write (player->GetWorldID ());
    addPlayerPacket.Write (player->GetTypeID ());
    addPlayerPacket.Write (player->GetID ());
    addPlayerPacket.Write (yap::Vector2 (100.0f, 100.0f));
//    addPlayerPacket.Write (player->GetState ());
//    addPlayerPacket.Write (player->GetDirection ());

    SendPacket (addPlayerPacket);
  }

  void Map::SendRemovePlayer (Player* player)
  {
  }
} // namespace yse
