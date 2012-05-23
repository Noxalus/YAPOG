#include "YAPOG/Game/World/Map/Physics/GridCollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"
#include "YAPOG/Game/World/Map/Physics/ICollidable.hpp"

namespace yap
{
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
    UIntRect collidableRect (
      collidable->GetTopLeft ().x / cellSize_.x,
      collidable->GetTopLeft ().y / cellSize_.y,
      (collidable->GetBottomRight ().x - collidable->GetTopLeft ().x) /
      cellSize_.x,
      (collidable->GetBottomRight ().y - collidable->GetTopLeft ().y) /
      cellSize_.y);

    for (uint y = collidableRect.top;
         y < collidableRect.top + collidableRect.height;
         ++y)
      for (uint x = collidableRect.left;
           x < collidableRect.left + collidableRect.width;
           ++x)
        cells_ (x, y)->AddCollidable (collidable);
  }
} // namespace yap
