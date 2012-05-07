#include "YAPOG/Game/World/Map/Map.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const String Map::DEFAULT_NAME = "<ANONYMOUS_MAP>";
  const uint Map::DEFAULT_WIDTH = 0;
  const uint Map::DEFAULT_HEIGHT = 0;

  Map::Map (const ID& id)
    : id_ (id)
    , name_ (DEFAULT_NAME)
    , width_ (DEFAULT_WIDTH)
    , height_ (DEFAULT_HEIGHT)
    , objects_ ()
    , dynamicObjects_ ()
    , updateables_ ()
  {
  }

  Map::~Map ()
  {
  }

  Map* Map::Clone () const
  {
    YAPOG_THROW("Invalid method call: `Map::Clone () const'.");
  }

  const ID& Map::GetID () const
  {
    return id_;
  }

  void Map::SetID (const ID& id)
  {
    id_ = id;
  }

  const String& Map::GetName () const
  {
    return name_;
  }

  void Map::SetName (const String& name)
  {
    name_ = name;
  }

  const uint& Map::GetWidth () const
  {
    return width_;
  }

  const uint& Map::GetHeight () const
  {
    return height_;
  }

  void Map::SetSize (uint width, uint height)
  {
    width_ = width;
    height_ = height;

    HandleSetSize (width, height);
  }

  void Map::HandleSetSize (uint width, uint height)
  {
  }

  void Map::Update (const Time& dt)
  {
    for (IUpdateable* updateable : updateables_)
      updateable->Update (dt);

    HandleUpdate (dt);
  }

  void Map::AddObject (WorldObject* object)
  {
    objects_.Add (object);
  }

  void Map::AddDynamicObject (DynamicWorldObject* object)
  {
    dynamicObjects_.AddObject (object);
    AddUpdateable (object);
  }

  void Map::AddUpdateable (IUpdateable* updateable)
  {
    updateables_.Add (updateable);
  }
} // namespace yap
