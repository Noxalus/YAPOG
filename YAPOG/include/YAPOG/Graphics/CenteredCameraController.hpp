#ifndef YAPOG_CENTEREDCAMERACONTROLLER_HPP
# define YAPOG_CENTEREDCAMERACONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/CameraController.hpp"

namespace yap
{
  class YAPOG_LIB CenteredCameraController : public CameraController
  {
      DISALLOW_COPY(CenteredCameraController);

    public:

      CenteredCameraController (ICamera& camera);
      virtual ~CenteredCameraController ();

    protected:

      virtual void HandleFocusTarget ();

      virtual void HandleUpdate (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_CENTEREDCAMERACONTROLLER_HPP
