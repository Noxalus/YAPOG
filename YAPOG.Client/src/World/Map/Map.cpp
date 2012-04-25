#include "World/Map/Map.hpp"

Map::Map (const yap::ID& id)
  : yap::Map (id)
  , tileLayers_ ()
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

void Map::Draw (yap::IDrawingContext& context)
{

}

bool Map::IsVisible () const
{
  return true;
}

void Map::Show (bool isVisible)
{
}

void Map::ChangeColor (const sf::Color& color)
{
}

void Map::HandleSetSize (uint width, uint height)
{
  tileLayers_.SetSize (width, height);
}
