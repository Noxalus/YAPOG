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

  bool GridCollidableArea::CollidesWith (
    const ICollidable& collidable,
    const Vector2& offset,
    const WorldObject& parent) const
  {
    UIntRect collidableRect;
    GetCollidableRectangle (collidable, offset, collidableRect);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        if (cells_ (x, y)->CollidesWith (collidable, offset, parent))
          return true;

    return false;
  }

  void GridCollidableArea::GetEventsCollidingWith (
    const ICollidable& collidable,
    MapEventQueue& events,
    DynamicWorldObject& parent) const
  {
    UIntRect collidableRect;
    GetCollidableRectangle (collidable, VECTOR2_ZERO, collidableRect);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->GetEventsCollidingWith (collidable, events, parent);
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
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->AddPhysicsCollidable (collidable, mapCollidableInfo);
  }

  void GridCollidableArea::HandleRemovePhysicsCollidable (
    ICollidable* collidable)
  {
    UIntRect collidableRect;
    GetCollidableRectangle (*collidable, collidableRect);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
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
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->AddEventCollidable (collidable, mapEventInfo);
  }

  void GridCollidableArea::HandleRemoveEventCollidable (
    ICollidable* collidable)
  {
    UIntRect collidableRect;
    GetCollidableRectangle (*collidable, collidableRect);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
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
    int left = collidable.GetTopLeft ().x + offset.x;
    int top = collidable.GetTopLeft ().y + offset.y;
    int right = collidable.GetBottomRight ().x + offset.x;
    int bottom = collidable.GetBottomRight ().y + offset.y;

    rectangle.left = MathHelper::Clamp (
      static_cast<int> (left / cellSize_.x),
      0,
      static_cast<int> (hSegmentCount_ - 1));

    rectangle.top = MathHelper::Clamp (
      static_cast<int> (top / cellSize_.y),
      0,
      static_cast<int> (vSegmentCount_ - 1));

    rectangle.width = MathHelper::Clamp (
      static_cast<int> ((right - left) / cellSize_.x + 1),
      0,
      static_cast<int> (hSegmentCount_ - rectangle.left));

    rectangle.height = MathHelper::Clamp (
      static_cast<int> ((bottom - top) / cellSize_.y + 1),
      0,
      static_cast<int> (vSegmentCount_ - rectangle.top));
  }
} // namespace yap
