#include "YAPOG/Graphics/CameraController.hpp"

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

  void CameraController::SetBounds (const FloatRect& bounds)
  {
    bounds_ = bounds;
  }

  void CameraController::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }
} // namespace yap
