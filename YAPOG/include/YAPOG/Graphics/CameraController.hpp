#ifndef YAPOG_CAMERACONTROLLER_HPP
# define YAPOG_CAMERACONTROLLER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct ICamera;
  struct ISpatial;

  class YAPOG_LIB CameraController : public IUpdateable
  {
      DISALLOW_COPY(CameraController);

    public:

      virtual ~CameraController ();

      void SetTarget (ISpatial& target);

      /// @brief Forces the controlled ICamera to jump into its target.
      void FocusTarget ();

      void SetBounds (const FloatRect& bounds);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      explicit CameraController (ICamera& camera);

      void CheckBounds (Vector2& offset);

      void CenterOnTarget ();

      virtual void HandleFocusTarget () = 0;

      virtual void HandleUpdate (const Time& dt) = 0;

      ICamera& camera_;
      ISpatial* target_;

      FloatRect bounds_;
  };
} // namespace yap

#endif // YAPOG_CAMERACONTROLLER_HPP
