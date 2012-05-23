#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"

namespace yap
{
  CollidableArea::CollidableArea ()
  {
  }

  CollidableArea::~CollidableArea ()
  {
  }

  void CollidableArea::SetSize (uint width, uint height)
  {
    HandleSetSize (width, height);
  }

  void CollidableArea::AddCollidable (ICollidable* collidable)
  {
    HandleAddCollidable (collidable);
  }

  void CollidableArea::HandleSetSize (uint width, uint height)
  {
  }
} // namespace yap
