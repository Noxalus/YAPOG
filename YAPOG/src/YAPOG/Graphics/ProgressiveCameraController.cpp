#include "YAPOG/Graphics/ProgressiveCameraController.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "YAPOG/Graphics/ISpatial.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  const float ProgressiveCameraController::CAMERA_MOVE_TRIGGER_LIMIT = 30.0f;
  const float ProgressiveCameraController::MOVE_AMORTIZATION_FACTOR = 150.0f;
  const float ProgressiveCameraController::DEFAULT_VELOCITY_FACTOR = 100.0f;

  ProgressiveCameraController::ProgressiveCameraController (ICamera& camera)
    : CameraController (camera)
    , velocityFactor_ (DEFAULT_VELOCITY_FACTOR)
  {
  }

  ProgressiveCameraController::~ProgressiveCameraController ()
  {
  }

  void ProgressiveCameraController::SetVelocityFactor (float velocityFactor)
  {
    velocityFactor_ = velocityFactor;
  }

  void ProgressiveCameraController::HandleUpdate (const Time& dt)
  {
    if (target_ == nullptr)
      return;

    Vector2 offset;

    const Vector2& targetPoint = target_->GetCenter ();
    Vector2 cameraSizeFactor = Vector2 (
      camera_.GetSize ().x / camera_.GetSize ().y,
      camera_.GetSize ().y / camera_.GetSize ().x);

    if (MathHelper::Abs (targetPoint.x - camera_.GetCenter ().x) >
        CAMERA_MOVE_TRIGGER_LIMIT * cameraSizeFactor.x)
      offset.x =
        velocityFactor_ *
        (targetPoint.x - camera_.GetCenter ().x) /
        MOVE_AMORTIZATION_FACTOR *
        cameraSizeFactor.y *
        dt.GetValue ();

    if (MathHelper::Abs (targetPoint.y - camera_.GetCenter ().y) >
        CAMERA_MOVE_TRIGGER_LIMIT * cameraSizeFactor.y)
      offset.y =
        velocityFactor_ *
        (targetPoint.y - camera_.GetCenter ().y) /
        MOVE_AMORTIZATION_FACTOR *
        cameraSizeFactor.x *
        dt.GetValue ();

    if (camera_.GetTopLeft ().x + offset.x < bounds_.left)
      offset.x = bounds_.left - camera_.GetTopLeft ().x;

    if (camera_.GetBottomRight ().x + offset.x >
        (bounds_.left + bounds_.width))
      offset.x = bounds_.left + bounds_.width - camera_.GetBottomRight ().x;

    if (camera_.GetTopLeft ().y + offset.y < bounds_.top)
      offset.y = bounds_.top - camera_.GetTopLeft ().y;

    if (camera_.GetBottomRight ().y + offset.y >
        (bounds_.top + bounds_.height))
      offset.y = bounds_.top + bounds_.height - camera_.GetBottomRight ().y;

    camera_.Move (offset);
  }
} // namespace yap
