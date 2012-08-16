#include "YAPOG/Graphics/Game/World/RegularWorldDrawingPolicy.hpp"
#include "YAPOG/Game/World/ISpatial3.hpp"

namespace yap
{
  RegularWorldDrawingPolicy::RegularWorldDrawingPolicy ()
    : WorldDrawingPolicy ()
  {
  }

  RegularWorldDrawingPolicy::~RegularWorldDrawingPolicy ()
  {
  }

  Vector2 RegularWorldDrawingPolicy::HandleToScreenPosition (
    const Vector3& worldPosition) const
  {
    return Vector2 (
      worldPosition.x,
      worldPosition.y - worldPosition.z * 32.0f); /// @warning [TMP]
  }

  float RegularWorldDrawingPolicy::HandleGetComparisonPoint (
    const ISpatial3& spatial) const
  {
    return spatial.GetBottomRight ().y;
  }
} // namespace yap
