#include "YAPOG/Game/World/Map/Physics/EventTriggerBoundingBoxCollection.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  EventTriggerBoundingBoxCollection::EventTriggerBoundingBoxCollection ()
    : BoundingBoxCollection ()
    , parent_ (nullptr)
  {
  }

  EventTriggerBoundingBoxCollection::~EventTriggerBoundingBoxCollection ()
  {
  }

  EventTriggerBoundingBoxCollection::EventTriggerBoundingBoxCollection (
    const EventTriggerBoundingBoxCollection& copy)
    : BoundingBoxCollection (copy)
    , parent_ (nullptr)
  {
    for (BoundingBox* boundingBox : copy.GetBoundingBoxes ())
      AddEventTriggerBoundingBox (new BoundingBox (*boundingBox));
  }

  void EventTriggerBoundingBoxCollection::AddEventTriggerBoundingBox (
    BoundingBox* boundingBox)
  {
    AddBoundingBox (boundingBox);
  }

  void EventTriggerBoundingBoxCollection::RemoveEventTriggerBoundingBox (
    BoundingBox* boundingBox)
  {
    RemoveBoundingBox (boundingBox);
  }

  void EventTriggerBoundingBoxCollection::SetCollidableArea (
    DynamicWorldObject& parent,
    CollidableArea* collidableArea)
  {
    parent_ = &parent;

    BoundingBoxCollection::SetCollidableArea (collidableArea);
  }

  void EventTriggerBoundingBoxCollection::GetEventsCollidingWith (
    const CollidableArea& collidableArea,
    MapEventQueue& events) const
  {
    for (const BoundingBox* boundingBox : GetBoundingBoxes ())
      collidableArea.GetEventsCollidingWith (*boundingBox, events, *parent_);
  }

  void
  EventTriggerBoundingBoxCollection::HandleAddBoundingBoxToCollidableArea (
    BoundingBox* boundingBox)
  {
  }

  void EventTriggerBoundingBoxCollection::
  HandleRemoveBoundingBoxFromCollidableArea (
    BoundingBox* boundingBox)
  {
  }
} // namespace yap
