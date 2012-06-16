#include "GameScreen/LoadingScreen.hpp"

namespace ycl
{
  const yap::ScreenType LoadingScreen::DEFAULT_NAME = "Loading";

  LoadingScreen::LoadingScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  LoadingScreen::~LoadingScreen ()
  {
  }

  void LoadingScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    nextScreen_ = "Update";

    BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
