#include "YAPOG/Game/World/Map/Physics/WorldObjectMoveController.hpp"

namespace yap
{
  const Vector2 WorldObjectMoveController::DEFAULT_VALUE =
    Vector2 (0.0f, 0.0f);

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

  void WorldObjectMoveController::SetValue (const Vector2& value)
  {
    value_ = value;
  }
} // namespace yap
