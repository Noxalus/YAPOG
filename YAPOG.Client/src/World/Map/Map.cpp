#include "World/Map/Map.hpp"

Map::Map ()
{
}

Map::~Map ()
{
}

yap::IClonable* Map::Clone () const
{
  return new Map ();
}
