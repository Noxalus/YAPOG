#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"

namespace ycl
{
  Map::Map (const yap::ID& id)
    : yap::Map (id)
    , tileLayers_ ()
    , drawableObjects_ ()
  {
  }

  Map::~Map ()
  {
  }

  void Map::AddTileLayer (
    yap::uint height,
    yap::TileLayoutHandler* tileLayoutHandler)
  {
    tileLayers_.AddTileLayer (height, tileLayoutHandler);
  }

  void Map::AddPlayer (Player* player)
  {
    player->SetMap (this);

    AddDynamicObject (player);
    AddDrawableObject (player);
  }

  void Map::AddDrawableObject (yap::IDrawableWorldObject* drawableObject)
  {
    drawableObjects_.Add (drawableObject);
  }

  void Map::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    tileLayers_.Draw (context);

    for (yap::IDrawableWorldObject* drawableObject : drawableObjects_)
      drawableObject->Draw (context);
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
    yap::Map::HandleSetSize (width, height);

    tileLayers_.SetSize (width, height);
  }

  void Map::HandleUpdate (const yap::Time& dt)
  {
    yap::Map::HandleUpdate (dt);
  }
} // namespace ycl
