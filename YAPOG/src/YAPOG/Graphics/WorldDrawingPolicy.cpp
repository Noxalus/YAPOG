#include "YAPOG/Graphics/WorldDrawingPolicy.hpp"

namespace yap
{
  WorldDrawingPolicy::WorldDrawingPolicy ()
  {
  }

  WorldDrawingPolicy::~WorldDrawingPolicy ()
  {
  }

  Vector2 WorldDrawingPolicy::GetDrawingPosition (
    const Vector3& worldPosition) const
  {
    return HandleGetDrawingPosition (worldPosition);
  }
} // namespace yap
