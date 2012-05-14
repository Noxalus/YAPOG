#include "World/World.hpp"
#include "World/Map/Map.hpp"

namespace ycl
{
  const bool World::DEFAULT_VISIBLE_STATE = true;
  const sf::Color World::DEFAULT_COLOR = sf::Color ();

  World::World ()
    : yap::World ()
    , isVisible_ (DEFAULT_VISIBLE_STATE)
    , color_ (DEFAULT_COLOR)
    , maps_ ()
  {
  }

  World::~World ()
  {
    for (Map* map : maps_)
      delete map;
  }

  void World::AddMap (Map* map)
  {
    maps_.Add (map);
  }

  void World::Draw (yap::IDrawingContext& context)
  {
    if (!IsVisible ())
      return;

    HandleDraw (context);
  }

  bool World::IsVisible () const
  {
    return isVisible_;
  }

  void World::Show (bool isVisible)
  {
    isVisible_ = isVisible;

    HandleShow (isVisible);
  }

  void World::ChangeColor (const sf::Color& color)
  {
    color_ = color;

    HandleChangeColor (color);
  }

  void World::HandleUpdate (const yap::Time& dt)
  {
    for (Map* map : maps_)
      map->Update (dt);
  }

  void World::HandleDraw (yap::IDrawingContext& context)
  {
    for (Map* map : maps_)
      map->Draw (context);
  }

  void World::HandleShow (bool isVisible)
  {
  }

  void World::HandleChangeColor (const sf::Color& color)
  {
    for (Map* map : maps_)
      map->ChangeColor (color);
  }
} // namespace ycl
