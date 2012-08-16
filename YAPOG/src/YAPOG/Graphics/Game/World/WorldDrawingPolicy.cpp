#include "YAPOG/Graphics/Game/World/WorldDrawingPolicy.hpp"

namespace yap
{
  WorldDrawingPolicy::WorldDrawingPolicy ()
  {
  }

  WorldDrawingPolicy::~WorldDrawingPolicy ()
  {
  }

  Vector2 WorldDrawingPolicy::ToScreenPosition (
    const Vector3& worldPosition) const
  {
    return HandleToScreenPosition (worldPosition);
  }

  Vector2 WorldDrawingPolicy::ToScreenOffset (
    const Vector3& worldOffset) const
  {
    return ToScreenPosition (worldOffset) - ToScreenPosition (VECTOR3_ZERO);
  }

  float WorldDrawingPolicy::GetComparisonPoint (
    const ISpatial3& spatial) const
  {
    return HandleGetComparisonPoint (spatial);
  }
} // namespace yap
