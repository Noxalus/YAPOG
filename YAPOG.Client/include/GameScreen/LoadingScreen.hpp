#ifndef YAPOG_CLIENT_LOADINGSCREEN_HPP
# define YAPOG_CLIENT_LOADINGSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"

namespace ycl
{
  class LoadingScreen : public BaseScreen
  {
      DISALLOW_COPY(LoadingScreen);

    public:

      LoadingScreen ();
      virtual ~LoadingScreen ();

    protected:

      virtual void HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:

      static const yap::ScreenType DEFAULT_NAME;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_LOADINGSCREEN_HPP
