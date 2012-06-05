#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/MapEventQueue.hpp"
#include "YAPOG/Game/World/Map/MapEventContext.hpp"

namespace yap
{
  CollidableAreaCell::CollidableAreaCell ()
    : physicsCollidables_ ()
    , eventCollidables_ ()
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

  void CollidableAreaCell::AddEventCollidable (
    ICollidable* collidable,
    const MapEventInfo::PtrType& mapEventInfo)
  {
    eventCollidables_.Add (collidable, mapEventInfo);
  }

  void CollidableAreaCell::RemoveEventCollidable (ICollidable* collidable)
  {
    eventCollidables_.Remove (collidable);
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

  void CollidableAreaCell::GetEventsCollidingWithObject (
    DynamicWorldObject& object,
    MapEventQueue& events) const
  {
    for (auto& it : eventCollidables_)
    {
      if (&it.second->GetParent () == &object)
      {
        // collidable belongs to object
        continue;
      }

      if (object.TriggerCollidesWith (*it.first))
        events.AddEvent (new MapEventContext (object, *it.first, *it.second));
    }
  }

  void CollidableAreaCell::Clear ()
  {
    physicsCollidables_.Clear ();
    eventCollidables_.Clear ();
  }
} // namespace yap
