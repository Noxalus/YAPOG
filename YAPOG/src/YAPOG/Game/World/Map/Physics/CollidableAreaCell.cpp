#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"

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
