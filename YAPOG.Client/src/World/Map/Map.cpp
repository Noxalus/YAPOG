#include "World/Map/Map.hpp"

Map::Map ()
{
}

Map::~Map ()
{
}

yap::IClonable* Map::Clone () const
{
  Map* clone = new Map ();

  clone->SetID (GetID ());
  clone->SetName (GetName ());

  return clone;
}
