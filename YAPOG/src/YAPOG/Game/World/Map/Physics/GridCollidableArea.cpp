#include "YAPOG/Game/World/Map/Physics/GridCollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"
#include "YAPOG/Game/World/Map/Physics/ICollidable.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const uint GridCollidableArea::MIN_VSEGMENT_COUNT = 1;
  const uint GridCollidableArea::MIN_HSEGMENT_COUNT = 1;

  GridCollidableArea::GridCollidableArea ()
    : CollidableArea ()
    , cellSize_ ()
    , cells_ (0, 0, nullptr)
  {
  }

  GridCollidableArea::~GridCollidableArea ()
  {
  }

  void GridCollidableArea::SetSegmentCount (
    uint vSegmentCount,
    uint hSegmentCount)
  {
    if (vSegmentCount < MIN_VSEGMENT_COUNT)
      YAPOG_THROW(
        "Invalid vertical segment count: `" +
        StringHelper::ToString (vSegmentCount) +
        "'.");

    if (hSegmentCount < MIN_HSEGMENT_COUNT)
      YAPOG_THROW(
        "Invalid horizontal segment count: `" +
        StringHelper::ToString (hSegmentCount) +
        "'.");

    vSegmentCount_ = vSegmentCount;
    hSegmentCount_ = hSegmentCount;

    cells_.Resize (
      hSegmentCount_,
      vSegmentCount_,
      new CollidableAreaCell ());
  }

  bool GridCollidableArea::CollidesWithObject (
    const WorldObject& object,
    const Vector2& offset) const
  {
    UIntRect objectRect;
    GetCollidableRectangle (object, offset, objectRect);

    for (uint y = objectRect.top;
         y <= objectRect.top + objectRect.height;
         ++y)
      for (uint x = objectRect.left;
           x <= objectRect.left + objectRect.width;
           ++x)
        if (cells_ (x, y)->CollidesWithObject (object, offset))
          return true;

    return false;
  }

  void GridCollidableArea::GetEventsCollidingWithObject (
    const DynamicWorldObject& object,
    MapEventQueue& events) const
  {
    UIntRect objectRect;
    GetCollidableRectangle (object, VECTOR2_ZERO, objectRect);

    for (uint y = objectRect.top;
         y <= objectRect.top + objectRect.height;
         ++y)
      for (uint x = objectRect.left;
           x <= objectRect.left + objectRect.width;
           ++x)
        cells_ (x, y)->GetEventsCollidingWithObject (object, events);
  }

  void GridCollidableArea::HandleSetSize (const Vector2& size)
  {
    CollidableArea::HandleSetSize (size);

    cellSize_ = Vector2 (size.x / hSegmentCount_, size.y / vSegmentCount_);
  }

  void GridCollidableArea::HandleAddPhysicsCollidable (
    ICollidable* collidable,
    const MapCollidableInfo::PtrType& mapCollidableInfo)
  {
    UIntRect collidableRect;
    GetCollidableRectangle (*collidable, collidableRect);

    for (uint y = collidableRect.top;
         y <= collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x <= collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->AddPhysicsCollidable (collidable, mapCollidableInfo);
  }

  void GridCollidableArea::HandleRemovePhysicsCollidable (
    ICollidable* collidable)
  {
    UIntRect collidableRect;
    GetCollidableRectangle (*collidable, collidableRect);

    for (uint y = collidableRect.top;
         y <= collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x <= collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->RemovePhysicsCollidable (collidable);
  }

  void GridCollidableArea::HandleAddEventCollidable (
    ICollidable* collidable,
    const MapEventInfo::PtrType& mapEventInfo)
  {
    UIntRect collidableRect;
    GetCollidableRectangle (*collidable, collidableRect);

    for (uint y = collidableRect.top;
         y <= collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x <= collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->AddEventCollidable (collidable, mapEventInfo);
  }

  void GridCollidableArea::HandleRemoveEventCollidable (
    ICollidable* collidable)
  {
    UIntRect collidableRect;
    GetCollidableRectangle (*collidable, collidableRect);

    for (uint y = collidableRect.top;
         y <= collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x <= collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->RemoveEventCollidable (collidable);
  }

  void GridCollidableArea::GetCollidableRectangle (
    const ICollidable& collidable,
    UIntRect& rectangle) const
  {
    GetCollidableRectangle (collidable, Vector2 (), rectangle);
  }

  void GridCollidableArea::GetCollidableRectangle (
    const ICollidable& collidable,
    const Vector2& offset,
    UIntRect& rectangle) const
  {
    uint left = collidable.GetTopLeft ().x + offset.x;
    uint top = collidable.GetTopLeft ().y + offset.y;
    uint right = collidable.GetBottomRight ().x + offset.x;
    uint bottom = collidable.GetBottomRight ().y + offset.y;

    rectangle.left = MathHelper::Clamp (
      static_cast<uint> (left / cellSize_.x),
      static_cast<uint> (0),
      hSegmentCount_ - 1);

    rectangle.top = MathHelper::Clamp (
      static_cast<uint> (top / cellSize_.y),
      static_cast<uint> (0),
      vSegmentCount_ - 1);

    rectangle.width = MathHelper::Clamp (
      static_cast<uint> ((right - left) / cellSize_.x),
      static_cast<uint> (0),
      hSegmentCount_ - rectangle.left);

    rectangle.height = MathHelper::Clamp (
      static_cast<uint> ((bottom - top) / cellSize_.y),
      static_cast<uint> (0),
      vSegmentCount_ - rectangle.top);
  }
} // namespace yap
