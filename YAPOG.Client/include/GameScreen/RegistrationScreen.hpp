#ifndef YAPOG_CLIENT_REGISTRATIONSCREEN_HPP
# define YAPOG_CLIENT_REGISTRATIONSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"
# include "Gui/RegistrationWidget.hpp"

namespace ycl
{
  class RegistrationScreen : public BaseScreen
  {
      DISALLOW_COPY(RegistrationScreen);

    public:

      RegistrationScreen ();
      virtual ~RegistrationScreen ();

    protected:

      virtual void HandleInit ();
      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

      virtual const yap::ScreenType& HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:

      RegistrationWidget registrationWidget_;

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_REGISTRATIONSCREEN_HPP
