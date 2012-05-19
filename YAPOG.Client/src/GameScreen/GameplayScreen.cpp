#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"

#include "GameScreen/GameplayScreen.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/Map.hpp"

namespace ycl
{
  const yap::ScreenType GameplayScreen::DEFAULT_NAME = "Gameplay";

  GameplayScreen::GameplayScreen (yap::ICamera& worldCamera)
    : BaseScreen (DEFAULT_NAME)
    , world_ ()
    , cameraController_ (worldCamera)
    , moveController_ ()
  {
  }

  GameplayScreen::~GameplayScreen ()
  {
  }

  void GameplayScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    // tmp
    world_.ChangeMap (yap::ID (1));
  }

  const yap::ScreenType& GameplayScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    world_.Update (dt);
    world_.Draw (context);

    /// @todo add a move controller, player etc, map loading
    /// and send applied forces to the server.

    return BaseScreen::HandleRun (dt, context);
  }

  bool GameplayScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (gameInputManager_.GameInputIsActivated (
          yap::GameInputType::Down,
          guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::South);
      return true;
    }

    if (gameInputManager_.GameInputIsActivated (
          yap::GameInputType::Up,
          guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::North);
      return true;
    }

    if (gameInputManager_.GameInputIsActivated (
          yap::GameInputType::Left,
          guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::West);
      return true;
    }

    if (gameInputManager_.GameInputIsActivated (
          yap::GameInputType::Right,
          guiEvent))
    {
      moveController_.EnableDirection (yap::Direction::East);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
          yap::GameInputType::Down,
          guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::South);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
          yap::GameInputType::Up,
          guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::North);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
          yap::GameInputType::Left,
          guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::West);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
          yap::GameInputType::Right,
          guiEvent))
    {
      moveController_.DisableDirection (yap::Direction::East);
      return true;
    }

    return false;
  }

  void GameplayScreen::SetCurrentMap (Map& map)
  {
    cameraController_.SetBounds (
      yap::FloatRect (
        yap::Vector2 (),
        map.GetSize ()));
  }

  void GameplayScreen::SetPlayer (Player* player)
  {
    player_ = player;

    player_->OnMapChanged += [&] (
      const Player& sender,
      const yap::ConstChangeEventArgs<Map*>& args)
    {
      SetCurrentMap (*args.Current);
    };

    cameraController_.SetTarget (*player);
    cameraController_.SetVelocityFactor (player->GetMaxVelocity ());
  }
} // namespace ycl
