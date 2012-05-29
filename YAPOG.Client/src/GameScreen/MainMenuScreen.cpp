#include "GameScreen/MainMenuScreen.hpp"

namespace ycl
{
  const yap::ScreenType MainMenuScreen::DEFAULT_NAME = "MainMenu";

  MainMenuScreen::MainMenuScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  MainMenuScreen::~MainMenuScreen ()
  {
  }

  const yap::ScreenType& MainMenuScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    nextScreen_ = "Battle";

    return BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
