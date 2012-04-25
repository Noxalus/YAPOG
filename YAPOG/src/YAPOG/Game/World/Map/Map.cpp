#include "YAPOG/Game/World/Map/Map.hpp"

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
  {
  }

  Map::~Map ()
  {
  }

  Map::Map (const Map& copy)
    : id_ (copy.id_)
    , name_ (copy.name_)
  {
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

  void Map::SetSize (uint width, uint height)
  {
    width_ = width;
    height_ = height;
  }

  void Map::HandleSetSize (uint width, uint height)
  {
  }
} // namespace yap
