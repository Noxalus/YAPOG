#ifndef YAPOG_CLIENT_MAINMENUSCREEN_HPP
# define YAPOG_CLIENT_MAINMENUSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class MainMenuScreen : public BaseScreen
  {
      DISALLOW_COPY(MainMenuScreen);

    public:

      MainMenuScreen ();
      virtual ~MainMenuScreen ();

    protected:

      virtual const yap::ScreenType& HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_MAINMENUSCREEN_HPP
