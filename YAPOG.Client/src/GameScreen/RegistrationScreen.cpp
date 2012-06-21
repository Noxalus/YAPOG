#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/RegistrationScreen.hpp"
#include "Client/Session.hpp"

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

  void RegistrationScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    BaseScreen::HandleRun (dt, context);
  }
  
  bool RegistrationScreen::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
  {
    if (guiEvent.type == sf::Event::KeyPressed)
    {
      if (guiEvent.key.code == sf::Keyboard::Escape)
      {
        nextScreen_ = "MainMenu";
        return true;
      }

      if (guiEvent.key.code == sf::Keyboard::Return)
      {
        yap::String login =
          registrationWidget_.GetLoginTextBox ().GetContent ();
        yap::String password =
          registrationWidget_.GetPasswordTextBox ().GetContent ();
        yap::String email =
          registrationWidget_.GetEmailTextBox ().GetContent ();

        session_.Register (login, password, email);

        //@todo Check
        nextScreen_ = "Gameplay";
        return true;
      }

    }
    return false;
  }
} // namespace ycl
