#include "YAPOG/Game/World/Map/Physics/GridCollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"
#include "YAPOG/Game/World/Map/Physics/ICollidable.hpp"
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
        StringHelper::ToString (vSegmentCount) +
        "'.");

    vSegmentCount_ = vSegmentCount;
    hSegmentCount_ = hSegmentCount;

    cells_.Resize (
      hSegmentCount_,
      vSegmentCount_,
      new CollidableAreaCell ());
  }

  void GridCollidableArea::HandleSetSize (const Vector2& size)
  {
    CollidableArea::HandleSetSize (size);

    cellSize_ = Vector2 (size.x / hSegmentCount_, size.y / vSegmentCount_);
  }

  void GridCollidableArea::HandleAddCollidable (ICollidable* collidable)
  {
    UIntRect collidableRect;
    GetRectangle (collidable, collidableRect);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->AddCollidable (collidable);
  }

  void GridCollidableArea::HandleRemoveCollidable (ICollidable* collidable)
  {
    UIntRect collidableRect;
    GetRectangle (collidable, collidableRect);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->RemoveCollidable (collidable);
  }

  void GridCollidableArea::GetRectangle (
    ICollidable* collidable,
    UIntRect& rectangle)
  {
    rectangle.left = MathHelper::Clamp (
      static_cast<uint> (collidable->GetTopLeft ().x / cellSize_.x),
      static_cast<uint> (0),
      hSegmentCount_ - 1);

    rectangle.top = MathHelper::Clamp (
      static_cast<uint> (collidable->GetTopLeft ().y / cellSize_.y),
      static_cast<uint> (0),
      vSegmentCount_ - 1);

    rectangle.width = MathHelper::Clamp (
      static_cast<uint> (
        (collidable->GetBottomRight ().x - collidable->GetTopLeft ().x) /
        cellSize_.x),
      static_cast<uint> (0),
      hSegmentCount_ - rectangle.left);

    rectangle.height = MathHelper::Clamp (
      static_cast<uint> (
        (collidable->GetBottomRight ().y - collidable->GetTopLeft ().y) /
        cellSize_.y),
      static_cast<uint> (0),
      vSegmentCount_ - rectangle.top);
  }
} // namespace yap
