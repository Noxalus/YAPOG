#include "YAPOG/Game/World/Map/Physics/GridCollidableArea.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableAreaCell.hpp"

namespace yap
{
  const Vector2 GridCollidableArea::DEFAULT_SIZE = Vector2 ();
  const Vector2 GridCollidableArea::DEFAULT_CELL_SIZE = Vector2 ();

  GridCollidableArea::GridCollidableArea ()
    : CollidableArea ()
    , size_ (DEFAULT_SIZE)
    , cellSize_ (DEFAULT_CELL_SIZE)
    , cells_ (0, 0, nullptr)
  {
  }

  GridCollidableArea::~GridCollidableArea ()
  {
  }

  void GridCollidableArea::SetSize (const Vector2& size)
  {
    size_ = size;
  }

  void GridCollidableArea::HandleSetSize (uint width, uint height)
  {
    CollidableArea::HandleSetSize (width, height);

    cellSize_ = Vector2 (size_.x / width, size_.y / height);

    cells_.Resize (width, height, new CollidableAreaCell ());
  }

  void GridCollidableArea::HandleAddCollidable (ICollidable* collidable)
  {
    /// @todo Add collidable in all cells where it is "present".
  }
} // namespace yap
