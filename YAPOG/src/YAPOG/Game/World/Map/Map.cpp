#include "YAPOG/Game/World/Map/Map.hpp"

namespace yap
{
  const String Map::DEFAULT_NAME = "<ANONYMOUS_MAP>";

  Map::Map (const ID& id)
    : id_ (id)
    , name_ (DEFAULT_NAME)
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
} // namespace yap
