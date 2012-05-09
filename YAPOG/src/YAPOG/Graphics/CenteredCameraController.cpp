#include "YAPOG/Graphics/CenteredCameraController.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "YAPOG/Graphics/ISpatial.hpp"

namespace yap
{
  CenteredCameraController::CenteredCameraController (ICamera& camera)
    : CameraController (camera)
  {
  }

  CenteredCameraController::~CenteredCameraController ()
  {
  }

  void CenteredCameraController::HandleUpdate (const Time& dt)
  {
    if (target_ == nullptr)
      return;

    const Vector2& targetPoint = target_->GetCenter ();
    Vector2 offset = targetPoint - camera_.GetCenter ();

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
