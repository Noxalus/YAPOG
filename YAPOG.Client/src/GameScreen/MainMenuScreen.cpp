#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"

#include "GameScreen/RegistrationScreen.hpp"
#include "GameScreen/MainMenuScreen.hpp"
#include "Gui/MainMenu.hpp"

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

  void MainMenuScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    MainMenu* mainMenu = new MainMenu ();
    mainMenu->Init ();

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

    mainMenu->GetLoginItem ().OnActivated +=
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      nextScreen_ = "Login";
    };

    mainMenu->GetRegistrationItem ().OnActivated +=
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      nextScreen_ = "Registration";
    };

    mainMenu->GetExitItem ().OnActivated +=
      [&] (const yap::MenuItem& sender, const yap::EmptyEventArgs& args)
    {
      ExitGame ();
    };

    guiManager_->AddChild (*mainMenu);

    yap::AudioManager::Instance ().PlayMusic ("BGM/Opening.ogg");
  }

  void MainMenuScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    BaseScreen::HandleRun (dt, context);
  }
} // namespace ycl
