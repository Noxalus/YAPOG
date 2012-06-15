#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"

#include "GameScreen/SplashScreen.hpp"

namespace ycl
{
  const yap::ScreenType SplashScreen::DEFAULT_NAME = "Splash";
  const yap::String SplashScreen::DEFAULT_SPLASH_TEXT = "Appuyez sur Start !";

  SplashScreen::SplashScreen ()
    : BaseScreen (DEFAULT_NAME)
    , logo_ (nullptr)
    , splashText_ (DEFAULT_SPLASH_TEXT)
  {
  }

  SplashScreen::~SplashScreen ()
  {
  }

  void SplashScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    logo_ = new yap::Sprite (yap::ObjectFactory::Instance ().
                             Create<yap::Texture> ("Texture", yap::ID (100)));

    logo_->Scale (yap::Vector2 (0.42f, 0.42f));
    logo_->SetPosition (yap::Vector2 (
                          800 / 2 - logo_->GetSize ().x / 2,
                          600 / 2 - logo_->GetSize ().y / 2));

    splashText_.ChangeColor (sf::Color::Black);
    splashText_.SetPosition (
      yap::Vector2 (
        400 - splashText_.GetSize ().x / 2,
        450.0f));
    guiManager_->AddChild (splashText_);
  }

  void SplashScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    logo_->Draw (context);

    BaseScreen::HandleRun (dt, context);
  }

  bool SplashScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (gameInputManager_.GameInputIsActivated (
          yap::GameInputType::Action,
          guiEvent))
    {
      nextScreen_ = "MainMenu";
      return true;
    }

    return false;
  }
} // namespace ycl
