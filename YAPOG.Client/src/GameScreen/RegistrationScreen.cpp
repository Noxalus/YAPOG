#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"

#include "GameScreen/RegistrationScreen.hpp"
#include "YAPOG/System/RandomHelper.hpp"
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

    yap::PictureBox* bg = new yap::PictureBox ();

    yap::RandomHelper* random;
    int nb = random->GetNext (0, 4242) % 5;
    switch (nb)
    {
    case 0:
      bg->SetPicture ("WindowSkins/BasicSkin/Background/mew.jpg");
      break;
    case 1:
      bg->SetPicture ("WindowSkins/BasicSkin/Background/fete.jpg");
      break;
    case 2:
      bg->SetPicture ("WindowSkins/BasicSkin/Background/rondoudou.jpg");
      break;
    case 3:
      bg->SetPicture ("WindowSkins/BasicSkin/Background/dresseur.jpg");
      break;
    case 4:
      bg->SetPicture ("WindowSkins/BasicSkin/Background/ronflex.gif");
      break;
    default:
      bg->SetPicture ("WindowSkins/BasicSkin/Background/ronflex.gif");
      break;
    }
    bg->SetSize (yap::Vector2 (800, 600));
    guiManager_->AddChild (*bg);
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
