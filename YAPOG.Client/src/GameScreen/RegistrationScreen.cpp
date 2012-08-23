#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

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

    session_.OnRegistrationValidation += [this] (
      Session& sender,
      const yap::EmptyEventArgs& args)
    {
      nextScreen_ = "MainMenu";
    };

    session_.OnRegistrationError += [this] (
      Session& sender,
      const yap::EmptyEventArgs& args)
    {
      registrationWidget_.SetErrorText ("Failed to register !");
    };

    yap::PictureBox* bg = new yap::PictureBox ();

    yap::RandomHelper* random;
    int nb = random->GetNext (0, 4242) % 5;
    switch (nb)
    {
    case 0:
      bg->SetPicture (new yap::Sprite ("WindowSkins/BasicSkin/Background/mew.jpg"));
      break;
    case 1:
      bg->SetPicture (new yap::Sprite ("WindowSkins/BasicSkin/Background/fete.jpg"));
      break;
    case 2:
      bg->SetPicture (new yap::Sprite ("WindowSkins/BasicSkin/Background/rondoudou.jpg"));
      break;
    case 3:
      bg->SetPicture (new yap::Sprite ("WindowSkins/BasicSkin/Background/dresseur.jpg"));
      break;
    case 4:
      bg->SetPicture (new yap::Sprite ("WindowSkins/BasicSkin/Background/ronflex.gif"));
      break;
    default:
      bg->SetPicture (new yap::Sprite ("WindowSkins/BasicSkin/Background/ronflex.gif"));
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

        //@todo Check

        session_.Register (login, password, email);

        return true;
      }

    }
    return false;
  }

  void RegistrationScreen::HandleDeactivate ()
  {
    registrationWidget_.GetLoginTextBox ().Clear ();
    registrationWidget_.GetPasswordTextBox ().Clear ();
    registrationWidget_.GetEmailTextBox ().Clear ();
    registrationWidget_.SetErrorText ("");
  }

} // namespace ycl
