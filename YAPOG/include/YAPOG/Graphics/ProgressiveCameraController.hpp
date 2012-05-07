#ifndef YAPOG_PROGRESSIVECAMERACONTROLLER_HPP
# define YAPOG_PROGRESSIVECAMERACONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/CameraController.hpp"

namespace yap
{
  class YAPOG_LIB ProgressiveCameraController : public CameraController
  {
      DISALLOW_COPY(ProgressiveCameraController);

    public:

      ProgressiveCameraController (ICamera& camera);
      virtual ~ProgressiveCameraController ();

      void SetVelocityFactor (float velocityFactor);

    protected:

      virtual void HandleUpdate (const Time& dt);

    private:

      static const float CAMERA_MOVE_TRIGGER_LIMIT;
      static const float MOVE_AMORTIZATION_FACTOR;
      static const float DEFAULT_VELOCITY_FACTOR;

      float velocityFactor_;
  };
} // namespace yap

#endif // YAPOG_PROGRESSIVECAMERACONTROLLER_HPP
