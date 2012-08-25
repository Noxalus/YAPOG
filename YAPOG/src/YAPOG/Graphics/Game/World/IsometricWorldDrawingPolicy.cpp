#include "YAPOG/Graphics/Game/World/IsometricWorldDrawingPolicy.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/Game/World/ISpatial3.hpp"

namespace yap
{
  IsometricWorldDrawingPolicy::IsometricWorldDrawingPolicy ()
    : WorldDrawingPolicy ()
  {
  }

  IsometricWorldDrawingPolicy::~IsometricWorldDrawingPolicy ()
  {
  }

  Vector2 IsometricWorldDrawingPolicy::HandleToScreenPosition (
    const Vector3& worldPosition) const
  {
    return Vector2 (
      (worldPosition.x - worldPosition.y),
      (-worldPosition.z * 32.0f + /// @warning [TMP]
       (worldPosition.x + worldPosition.y) * .5f));
  }

  float IsometricWorldDrawingPolicy::HandleGetComparisonPoint (
    const ISpatial3& spatial) const
  {
    return
      spatial.GetPosition ().x +
      spatial.GetPosition ().y;
  }
} // namespace yap
