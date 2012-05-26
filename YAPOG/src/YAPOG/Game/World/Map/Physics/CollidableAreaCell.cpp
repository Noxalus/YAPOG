#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"

namespace yap
{
  CollidableAreaCell::CollidableAreaCell ()
    : collidables_ ()
  {
  }

  void CollidableAreaCell::AddCollidable (ICollidable* collidable)
  {
    collidables_.Add (collidable);
  }

  void CollidableAreaCell::RemoveCollidable (ICollidable* collidable)
  {
    collidables_.Remove (collidable);
  }

  bool CollidableAreaCell::CollidesWithObject (const WorldObject& object) const
  {
    for (ICollidable* collidable : collidables_)
      if (object.CollidesWith (*collidable))
        return true;

    return false;
  }

  bool CollidableAreaCell::CollidesWithObject (
    const WorldObject& object,
    const Vector2& offset) const
  {
    for (ICollidable* collidable : collidables_)
      if (object.CollidesWith (*collidable, offset))
        return true;

    return false;
  }

  void CollidableAreaCell::Clear ()
  {
    collidables_.Clear ();
  }

  CollidableAreaCell::ItType CollidableAreaCell::begin ()
  {
    return collidables_.begin ();
  }

  CollidableAreaCell::ItType CollidableAreaCell::end ()
  {
    return collidables_.end ();
  }

  CollidableAreaCell::ConstItType CollidableAreaCell::begin () const
  {
    return collidables_.begin ();
  }

  CollidableAreaCell::ConstItType CollidableAreaCell::end () const
  {
    return collidables_.end ();
  }
} // namespace yap
