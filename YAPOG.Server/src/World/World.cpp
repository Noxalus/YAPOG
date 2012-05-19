#include "World/World.hpp"
#include "World/Map/Map.hpp"

namespace yse
{
  World::World ()
    : yap::World ()
    , maps_ ()
  {
  }

  World::~World ()
  {
  }

  void World::AddMap (Map* map)
  {
    maps_.Add (map);
  }

  void World::HandleUpdate (const yap::Time& dt)
  {
    yap::World::HandleUpdate (dt);

    for (Map* map : maps_)
      map->Update (dt);
  }
} // namespace yse
