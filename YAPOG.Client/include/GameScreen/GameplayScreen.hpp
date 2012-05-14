#ifndef YAPOG_CLIENT_GAMEPLAYSCREEN_HPP
# define YAPOG_CLIENT_GAMEPLAYSCREEN_HPP

# include "YAPOG/Macros.hpp"

# include "GameScreen/BaseScreen.hpp"
# include "World/World.hpp"

namespace ycl
{
  class GameplayScreen : public BaseScreen
  {
      DISALLOW_COPY(GameplayScreen);

    public:

      GameplayScreen ();
      virtual ~GameplayScreen ();

    protected:

      virtual const yap::ScreenType& HandleRun (
        const yap::Time& dt,
        yap::IDrawingContext& context);

    private:

      World world_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_GAMEPLAYSCREEN_HPP
