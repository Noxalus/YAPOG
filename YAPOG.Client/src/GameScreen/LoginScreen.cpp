#include "YAPOG/System/IOStream.hpp"
#include "YAPOG/Graphics/Gui/Label.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Padding.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/MenuItem.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/DialogBoxWidget.hpp"

#include "Game.hpp"

#include "Gui/GameMainMenu.hpp"
#include "GameScreen/LoginScreen.hpp"
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

        session_.Login (login);
        nextScreen_ = "Gameplay";
        return true;
      }

    }
    return false;
  }
} // namespace ycl
