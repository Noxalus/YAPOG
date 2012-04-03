#include "YAPOG/Game/World/Map/Map.hpp"

namespace yap
{
  const String Map::DEFAULT_NAME = "Map";

  Map::Map (const ID& id)
    : id_ (id)
    , name_ (DEFAULT_NAME)
  {
  }

  Map::~Map ()
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
} // namespace yap
