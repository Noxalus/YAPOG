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

  bool CollidableAreaCell::CollidesWith (
    const ICollidable& collidable,
    const Vector2& offset,
    const WorldObject& parent) const
  {
    for (auto& it : physicsCollidables_)
    {
      if (&it.second->GetParent () == &parent)
        continue;

      if (collidable.CollidesWith (*it.first, offset))
        return true;
    }

    return false;
  }

  void CollidableAreaCell::GetEventsCollidingWith (
    const ICollidable& collidable,
    MapEventQueue& events,
    DynamicWorldObject& parent) const
  {
    for (auto& it : eventCollidables_)
    {
      if (&it.second->GetParent () == &parent)
        continue;

      if (collidable.CollidesWith (*it.first))
        events.AddEvent (new MapEventContext (parent, collidable, *it.second));
    }
  }

  void CollidableAreaCell::Clear ()
  {
    physicsCollidables_.Clear ();
    eventCollidables_.Clear ();
  }
} // namespace yap
