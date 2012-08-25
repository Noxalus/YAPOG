#ifndef YAPOG_CLIENT_SPLASHSCREEN_HPP
# define YAPOG_CLIENT_SPLASHSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"

namespace yap
{
  struct ISprite;
}

namespace ycl
{
  class SplashScreen : public BaseScreen
  {
      DISALLOW_COPY(SplashScreen);

    public:

      explicit SplashScreen (yap::IDrawingContext& context);
      virtual ~SplashScreen ();

    protected:

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

      virtual void HandleInit ();
      virtual void HandleActivate ();
      virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);

    private:
      yap::ISprite* logo_;
      yap::Label splashText_;

      static const yap::ScreenType DEFAULT_NAME;
      static const yap::String DEFAULT_SPLASH_TEXT;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_SPLASHSCREEN_HPP
