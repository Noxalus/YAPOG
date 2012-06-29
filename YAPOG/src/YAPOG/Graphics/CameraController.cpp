#include "YAPOG/Graphics/CameraController.hpp"
#include "YAPOG/Graphics/ICamera.hpp"

namespace yap
{
  CameraController::CameraController (ICamera& camera)
    : camera_ (camera)
    , target_ (nullptr)
    , bounds_ ()
  {
  }

  CameraController::~CameraController ()
  {
  }

  void CameraController::SetTarget (ISpatial& target)
  {
    target_ = &target;
  }

  void CameraController::FocusTarget ()
  {
    HandleFocusTarget ();
  }

  void CameraController::SetBounds (const FloatRect& bounds)
  {
    bounds_ = bounds;
  }

  void CameraController::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void CameraController::CheckBounds (Vector2& offset)
  {
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
  }

  void CameraController::CenterOnTarget ()
  {
    if (target_ == nullptr)
      return;

    const Vector2& targetPoint = target_->GetCenter ();
    Vector2 offset = targetPoint - camera_.GetCenter ();

    CheckBounds (offset);

    camera_.Move (offset);
  }
} // namespace yap
