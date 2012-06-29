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

  void CenteredCameraController::HandleFocusTarget ()
  {
    CenterOnTarget ();
  }

  void CenteredCameraController::HandleUpdate (const Time& dt)
  {
    CenterOnTarget ();
  }
} // namespace yap
