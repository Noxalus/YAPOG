#include "GameScreen/UpdateScreen.hpp"

namespace ycl
{
  const yap::ScreenType UpdateScreen::DEFAULT_NAME = "Update";

  UpdateScreen::UpdateScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  UpdateScreen::~UpdateScreen ()
  {
  }

  const yap::ScreenType& UpdateScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    nextScreen_ = "Login";

    return BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
