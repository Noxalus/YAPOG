#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"

namespace yap
{
  CollidableAreaCell::CollidableAreaCell ()
    : physicsCollidables_ ()
  {
  }

  void CollidableAreaCell::AddPhysicsCollidable (
    ICollidable* collidable,
    const MapCollidableInfo::PtrType& mapCollidableInfo)
  {
    physicsCollidables_.Add (collidable, mapCollidableInfo);
  }

  void CollidableAreaCell::RemovePhysicsCollidable (ICollidable* collidable)
  {
    physicsCollidables_.Remove (collidable);
  }

  bool CollidableAreaCell::CollidesWithObject (const WorldObject& object) const
  {
    return CollidesWithObject (object, Vector2 (0.0f, 0.0f));
  }

  bool CollidableAreaCell::CollidesWithObject (
    const WorldObject& object,
    const Vector2& offset) const
  {
    for (auto& it : physicsCollidables_)
    {
      if (&it.second->GetParent () == &object)
      {
        // collidable belongs to object
        continue;
      }

      if (object.CollidesWith (*it.first, offset))
        return true;
    }

    return false;
  }

  void CollidableAreaCell::Clear ()
  {
    physicsCollidables_.Clear ();
  }
} // namespace yap
