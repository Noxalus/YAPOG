#include "World/Map/Map.hpp"

namespace yse
{
  Map::Map (const yap::ID& id)
    : yap::Map (id)
  {
  }

  Map::~Map ()
  {
  }

  bool Map::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool Map::SendPacket (yap::IPacket& packet)
  {
    return packetSender_.SendPacket (packet);
  }
} // namespace yse
