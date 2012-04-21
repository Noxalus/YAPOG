#include "World/Map/Map.hpp"

Map::Map (const yap::ID& id)
  : yap::Map (id)
{
}

Map::~Map ()
{
}

Map::Map (const Map& copy)
  : yap::Map (copy)
{
}

Map* Map::Clone () const
{
  return new Map (*this);
}
