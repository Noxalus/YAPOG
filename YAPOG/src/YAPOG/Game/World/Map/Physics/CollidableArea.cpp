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

  void CollidableArea::AddCollidable (ICollidable* collidable)
  {
    HandleAddCollidable (collidable);
  }

  void CollidableArea::RemoveCollidable (ICollidable* collidable)
  {
    HandleRemoveCollidable (collidable);
  }

  void CollidableArea::HandleSetSize (const Vector2& size)
  {
  }
} // namespace yap
