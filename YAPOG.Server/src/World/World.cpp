#include "World/World.hpp"
#include "World/Map/Map.hpp"

namespace yse
{
  World::World ()
    : yap::World ()
    , maps_ ()
    , packetHandler_ ()
    , packetSender_ ()
  {
  }

  World::~World ()
  {
  }

  void World::AddMap (Map* map)
  {
    maps_.Add (map);
  }

  bool World::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool World::SendPacket (yap::IPacket& packet)
  {
    return packetSender_.SendPacket (packet);
  }

  void World::HandleUpdate (const yap::Time& dt)
  {
    yap::World::HandleUpdate (dt);

    for (Map* map : maps_)
      map->Update (dt);
  }
} // namespace yse
