#include "YAPOG/Game/Factory/ObjectFactory.hpp"

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
    , currentMapID_ ()
    , currentMap_ (nullptr)
    , maps_ ()
  {
  }

  World::~World ()
  {
  }

  void World::ChangeMap (const yap::ID& id)
  {
    if (currentMapID_ == id)
      return;

    currentMapID_ = id;

    if (!maps_.Contains (currentMapID_))
      AddMap (currentMapID_);

    currentMap_ = maps_[currentMapID_];
  }

  void World::AddMap (const yap::ID& id)
  {
    AddMap (yap::ObjectFactory::Instance ().Get<Map> ("Map", id));
  }

  void World::AddMap (Map* map)
  {
    maps_.Add (map->GetID (), map);
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
    currentMap_->Update (dt);
  }

  void World::HandleDraw (yap::IDrawingContext& context)
  {
    currentMap_->Draw (context);
  }

  void World::HandleShow (bool isVisible)
  {
  }

  void World::HandleChangeColor (const sf::Color& color)
  {
    for (auto& it : maps_)
      it.second->ChangeColor (color);
  }
} // namespace ycl
