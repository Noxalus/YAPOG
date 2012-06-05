#include "YAPOG/Game/World/Map/Physics/EventBoundingBoxCollection.hpp"
#include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yap
{
  EventBoundingBoxCollection::EventBoundingBoxCollection ()
    : BoundingBoxCollection ()
    , parent_ (nullptr)
    , eventBoundingBoxes_ ()
  {
  }

  EventBoundingBoxCollection::~EventBoundingBoxCollection ()
  {
  }

  EventBoundingBoxCollection::EventBoundingBoxCollection (
    const EventBoundingBoxCollection& copy)
    : BoundingBoxCollection (copy)
    , parent_ (nullptr)
    , eventBoundingBoxes_ ()
  {
  }

  void EventBoundingBoxCollection::AddEventBoundingBox (
    BoundingBox* boundingBox,
    MapEvent* event)
  {
    eventBoundingBoxes_.Add (boundingBox, event);

    AddBoundingBox (boundingBox);
  }

  void EventBoundingBoxCollection::RemoveEventBoundingBox (
    BoundingBox* boundingBox)
  {
    eventBoundingBoxes_.Remove (boundingBox);

    RemoveBoundingBox (boundingBox);
  }

  void EventBoundingBoxCollection::SetCollidableArea (
    DynamicWorldObject& parent,
    CollidableArea* collidableArea)
  {
    parent_ = &parent;

    BoundingBoxCollection::SetCollidableArea (collidableArea);
  }

  void EventBoundingBoxCollection::HandleAddBoundingBoxToCollidableArea (
    BoundingBox* boundingBox)
  {
    GetCollidableArea ().AddEventCollidable (
      boundingBox,
      MapEventInfo::PtrType (
        new MapEventInfo (
          *boundingBox,
          *eventBoundingBoxes_[boundingBox],
          *parent_)));
  }

  void EventBoundingBoxCollection::HandleRemoveBoundingBoxFromCollidableArea (
    BoundingBox* boundingBox)
  {
    GetCollidableArea ().RemoveEventCollidable (boundingBox);
  }
} // namespace yap
