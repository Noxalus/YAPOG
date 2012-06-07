#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"

namespace yap
{
  CollidableArea::CollidableArea ()
  {
  }

  CollidableArea::~CollidableArea ()
  {
  }

  void CollidableArea::SetSize (const Vector2& size)
  {
    size_ = size;

    HandleSetSize (size);
  }

  void CollidableArea::AddPhysicsCollidable (
    ICollidable* collidable,
    const MapCollidableInfo::PtrType& mapCollidableInfo)
  {
    HandleAddPhysicsCollidable (collidable, mapCollidableInfo);
  }

  void CollidableArea::RemovePhysicsCollidable (ICollidable* collidable)
  {
    HandleRemovePhysicsCollidable (collidable);
  }

  void CollidableArea::AddEventCollidable (
    ICollidable* collidable,
    const MapEventInfo::PtrType& mapEventInfo)
  {
    HandleAddEventCollidable (collidable, mapEventInfo);
  }

  void CollidableArea::RemoveEventCollidable (ICollidable* collidable)
  {
    HandleRemoveEventCollidable (collidable);
  }

  void CollidableArea::HandleSetSize (const Vector2& size)
  {
  }
} // namespace yap
