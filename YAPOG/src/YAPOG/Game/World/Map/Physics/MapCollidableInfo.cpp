#include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"

namespace yap
{
  MapCollidableInfo::MapCollidableInfo (
    const ICollidable& collidable,
    const WorldObject& parent)
    : collidable_ (collidable)
    , parent_ (parent)
  {
  }

  const ICollidable& MapCollidableInfo::GetCollidable () const
  {
    return collidable_;
  }

  const WorldObject& MapCollidableInfo::GetParent () const
  {
    return parent_;
  }
} // namespace yap
