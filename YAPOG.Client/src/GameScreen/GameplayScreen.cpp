#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/IO/Log/Logger.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"

#include "GameScreen/GameplayScreen.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/Map.hpp"
#include "Client/Session.hpp"
#include "Gui/PokedexWidget.hpp"

namespace ycl
{
  const yap::ScreenType GameplayScreen::DEFAULT_NAME = "Gameplay";

  GameplayScreen::GameplayScreen (yap::ICamera& worldCamera)
    : BaseScreen (DEFAULT_NAME)
    , world_ ()
    , cameraController_ (worldCamera)
    , player_ (nullptr)
    , moveController_ ()
    , lastForce_ ()
  {
    session_.GetUser ().OnPlayerCreated += [&] (
      const User& sender,
      Player* args)
    {
      SetPlayer (args);
    };

    world_.OnMapChanged += [&] (
      const World& sender,
      const yap::ChangeEventArgs<Map*>& args)
    {
      SetCurrentMap (*args.Current);
    };

    session_.GetUser ().SetWorld (&world_);
  }

  GameplayScreen::~GameplayScreen ()
  {
  }

  void GameplayScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    PokedexWidget* pokedex = new PokedexWidget ();
    pokedex->Init ();

    guiManager_->AddChild (*pokedex);
  }

  const yap::ScreenType& GameplayScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    world_.Update (dt);

    cameraController_.Update (dt);

    UpdatePlayer (dt);

    world_.Draw (context);
    
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

  Map& GameplayScreen::GetCurrentMap ()
  {
    return world_.GetCurrentMap ();
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

    moveController_.SetValue (player_->GetMaxVelocity ());

    cameraController_.SetTarget (*player);
    cameraController_.SetVelocityFactor (player->GetMaxVelocity ());
  }

  void GameplayScreen::UpdatePlayer (const yap::Time& dt)
  {
    if (player_ == nullptr)
      return;

    const yap::Vector2& force = moveController_.GetForce ();

    if (lastForce_ == force)
      return;

    SendApplyForce (force);

    player_->ApplyForce (force);

    lastForce_ = force;
  }

  void GameplayScreen::SendApplyForce (const yap::Vector2& force)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoApplyForce);

    packet.Write (force);

    session_.SendPacket (packet);
  }
} // namespace ycl
