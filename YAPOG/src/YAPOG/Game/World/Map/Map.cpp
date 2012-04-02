#include "YAPOG/Game/World/Map/Map.hpp"

namespace yap
{
  Map::Map ()
    : id_ ()
    , name_ ()
  {
  }

  Map::~Map ()
  {
  }

  const ID& Map::GetID () const
  {
    return id_;
  }

  void Map::ChangeID (const ID& id)
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
