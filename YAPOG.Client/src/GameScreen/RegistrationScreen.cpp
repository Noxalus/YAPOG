#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/RegistrationScreen.hpp"

namespace ycl
{
  const yap::ScreenType RegistrationScreen::DEFAULT_NAME = "Registration";

  RegistrationScreen::RegistrationScreen ()
    : BaseScreen (DEFAULT_NAME)
    , registrationWidget_ ()
  {
    registrationWidget_.Init ();
  }

  RegistrationScreen::~RegistrationScreen ()
  {
  }

  void RegistrationScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    guiManager_->AddChild (registrationWidget_);
  }

  const yap::ScreenType& RegistrationScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    return BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
