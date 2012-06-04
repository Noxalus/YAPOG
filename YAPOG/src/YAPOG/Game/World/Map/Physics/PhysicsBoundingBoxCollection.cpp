#include "YAPOG/Game/World/Map/Physics/PhysicsBoundingBoxCollection.hpp"
#include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yap
{
  PhysicsBoundingBoxCollection::PhysicsBoundingBoxCollection ()
    : BoundingBoxCollection ()
    , parent_ (nullptr)
  {
  }

  PhysicsBoundingBoxCollection::~PhysicsBoundingBoxCollection ()
  {
  }

  PhysicsBoundingBoxCollection::PhysicsBoundingBoxCollection (
    const PhysicsBoundingBoxCollection& copy)
    : BoundingBoxCollection (copy)
    , parent_ (nullptr)
  {
    for (BoundingBox* boundingBox : copy.GetBoundingBoxes ())
      AddPhysicsBoundingBox (new BoundingBox (*boundingBox));
  }

  void PhysicsBoundingBoxCollection::AddPhysicsBoundingBox (
    BoundingBox* boundingBox)
  {
    AddBoundingBox (boundingBox);
  }

  void PhysicsBoundingBoxCollection::RemovePhysicsBoundingBox (
    BoundingBox* boundingBox)
  {
    RemoveBoundingBox (boundingBox);
  }

  void PhysicsBoundingBoxCollection::SetCollidableArea (
    const WorldObject& parent,
    CollidableArea* collidableArea)
  {
    parent_ = &parent;

    BoundingBoxCollection::SetCollidableArea (collidableArea);
  }

  void PhysicsBoundingBoxCollection::HandleAddBoundingBoxToCollidableArea (
    BoundingBox* boundingBox)
  {
    GetCollidableArea ().AddPhysicsCollidable (
      boundingBox,
      MapCollidableInfo::PtrType (
        new MapCollidableInfo (
          *boundingBox,
          *parent_)));
  }

  void PhysicsBoundingBoxCollection::HandleRemoveBoundingBoxFromCollidableArea (
    BoundingBox* boundingBox)
  {
    GetCollidableArea ().RemoveEventCollidable (boundingBox);
  }
} // namespace yap
