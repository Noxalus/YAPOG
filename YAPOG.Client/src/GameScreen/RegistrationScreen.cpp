#include "GameScreen/RegistrationScreen.hpp"

namespace ycl
{
  const yap::ScreenType RegistrationScreen::DEFAULT_NAME = "Registration";

  RegistrationScreen::RegistrationScreen ()
    : BaseScreen (DEFAULT_NAME)
  {
  }

  RegistrationScreen::~RegistrationScreen ()
  {
  }

  const yap::ScreenType& RegistrationScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    nextScreen_ = "Battle";

    return BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
