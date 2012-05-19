#include "YAPOG/Game/World/Map/Physics/WorldObjectMoveController.hpp"

namespace yap
{
  const float WorldObjectMoveController::DEFAULT_VALUE = 0.0f;

  WorldObjectMoveController::WorldObjectMoveController ()
    : force_ ()
    , value_ (DEFAULT_VALUE)
  {
  }

  WorldObjectMoveController::~WorldObjectMoveController ()
  {
  }

  const Vector2& WorldObjectMoveController::GetForce () const
  {
    return force_;
  }

  void WorldObjectMoveController::SetValue (float value)
  {
    value_ = value;
  }
} // namespace yap
