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
  , tileLayers_ (copy.tileLayers_)
{
}

Map* Map::Clone () const
{
  return new Map (*this);
}

void Map::AddTileLayer (yap::uint height, yap::TileLayoutHandler* tileLayoutHandler)
{
  tileLayers_.AddTileLayer (height, tileLayoutHandler);
}

void Map::Draw (yap::IDrawingContext& context)
{
  if (!IsVisible ())
    return;

  tileLayers_.Draw (context);
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

void Map::HandleSetSize (yap::uint width, yap::uint height)
{
  tileLayers_.SetSize (width, height);
}
