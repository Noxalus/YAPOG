#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "GameScreen/LoginScreen.hpp"
#include "Gui/GameMainMenu.hpp"
#include "Client/Session.hpp"

namespace ycl
{
  const yap::ScreenType LoginScreen::DEFAULT_NAME = "Login";

  LoginScreen::LoginScreen ()
    : BaseScreen (DEFAULT_NAME)
    , loginWidget_ ()
  {
    loginWidget_.Init ();
  }

  LoginScreen::~LoginScreen ()
  {
  }

  void LoginScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    session_.OnLoginValidation += [this] (
      Session& sender,
      const yap::EmptyEventArgs& args)
    {
      nextScreen_ = "Gameplay";
    };

    session_.OnLoginError += [this] (
      Session& sender,
      const yap::EmptyEventArgs& args)
    {
      loginWidget_.SetErrorText ("Failed to login !");
    };

    yap::PictureBox* bg = new yap::PictureBox ();

    yap::RandomHelper* random;
    int nb = random->GetNext (0, 4242) % 5;
    switch (nb)
    {
    case 0:
      bg->SetPicture (
        new yap::Sprite ("WindowSkins/BasicSkin/Background/mew.jpg"));
      break;
    case 1:
      bg->SetPicture (
        new yap::Sprite ("WindowSkins/BasicSkin/Background/fete.jpg"));
      break;
    case 2:
      bg->SetPicture (
        new yap::Sprite ("WindowSkins/BasicSkin/Background/rondoudou.jpg"));
      break;
    case 3:
      bg->SetPicture (
        new yap::Sprite ("WindowSkins/BasicSkin/Background/dresseur.jpg"));
      break;
    case 4:
      bg->SetPicture (
        new yap::Sprite ("WindowSkins/BasicSkin/Background/ronflex.gif"));
      break;
    default:
      bg->SetPicture (
        new yap::Sprite ("WindowSkins/BasicSkin/Background/ronflex.gif"));
      break;
    }
    bg->SetSize (yap::Vector2 (800, 600));
    guiManager_->AddChild (*bg);
    guiManager_->AddChild (loginWidget_);
  }

  void LoginScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    BaseScreen::HandleRun (dt, context);
  }

  bool LoginScreen::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
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
        yap::String login = loginWidget_.GetLoginTextBox ().GetContent ();
        yap::String password = loginWidget_.GetPasswordTextBox ().GetContent ();

        session_.Login (login, password);

        return true;
      }

    }
    return false;
  }

  void LoginScreen::HandleDeactivate ()
  {
    loginWidget_.GetLoginTextBox ().Clear ();
    loginWidget_.GetPasswordTextBox ().Clear ();
    loginWidget_.SetErrorText ("");
  }

} // namespace ycl
