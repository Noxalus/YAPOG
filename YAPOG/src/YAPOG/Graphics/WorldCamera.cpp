#include "YAPOG/Graphics/WorldCamera.hpp"

namespace yap
{
  WorldCamera::WorldCamera (const Vector2& position, const Vector2& size)
    : Camera (position, size)
    , worldDrawingPolicy_ (nullptr)
  {
  }

  WorldCamera::~WorldCamera ()
  {
  }

  void WorldCamera::SetWorldDrawingPolicy (
    const IWorldDrawingPolicy& worldDrawingPolicy)
  {
    worldDrawingPolicy_ = &worldDrawingPolicy;
  }

  bool WorldCamera::HandleIsInView (
    const Vector2& point,
    const Vector2& size) const
  {
    return Camera::HandleIsInView (point, size);
  }

  Vector2 WorldCamera::HandleToLocal (const Vector2& globalPoint) const
  {
    return Camera::HandleToLocal (globalPoint);
  }

  Vector2 WorldCamera::HandleToGlobal (const Vector2& localPoint) const
  {
    return Camera::HandleToGlobal (localPoint);
  }
} // namespace yap
