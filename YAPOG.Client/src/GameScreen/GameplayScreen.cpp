#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/Network/Packet.hpp"
#include "YAPOG/System/IO/Log/Logger.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"
#include "YAPOG/Graphics/Gui/WidgetBorder.hpp"
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
#include "YAPOG/Graphics/Gui/VerticalLayout.hpp"
#include "YAPOG/Graphics/Gui/Menu.hpp"
#include "YAPOG/Graphics/Gui/PictureBox.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Graphics/Gui/TextBoxWidget.hpp"
#include "YAPOG/Graphics/Gui/GridMenu.hpp"
#include "YAPOG/Graphics/Gui/MultiLabelWidget.hpp"

#include "GameScreen/GameplayScreen.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/Map.hpp"
#include "Client/Session.hpp"
#include "Gui/ChatWidget.hpp"
#include "Gui/PokedexWidget.hpp"
#include "Gui/PokedexCompositeWidget.hpp"

/// @warning Tests.
/// @todo Remove from here.
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/AnyMapEventAction.hpp"
#include "World/Map/NPC.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
ycl::NPC* npc1_ = nullptr;

namespace ycl
{
  const yap::ScreenType GameplayScreen::DEFAULT_NAME = "Gameplay";

  const yap::Vector2 GameplayScreen::DEFAULT_WORLD_CAMERA_DEZOOM_FACTOR =
    yap::Vector2 (1.0f, 1.0f);

  GameplayScreen::GameplayScreen (yap::ICamera& worldCamera)
    : BaseScreen (DEFAULT_NAME)
    , world_ ()
    , worldCamera_ (worldCamera)
    , cameraController_ (worldCamera_)
    , player_ (nullptr)
    , moveController_ ()
    , lastForce_ ()
    , pokedex_ (nullptr)
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

    ChatWidget* chat = new ChatWidget ();
    chat->Init ();

    worldCamera_.Scale (DEFAULT_WORLD_CAMERA_DEZOOM_FACTOR);

    guiManager_->AddChild (*chat);
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

    /// @warning Tests.
    /// @todo Remove from here.
    /// to see below too !
    npc1_ = objectFactory_.Create<NPC> ("NPC", yap::ID (1));
    npc1_->SetWorldID (yap::ID (4222));
    npc1_->Move (yap::Vector2 (260.0f, 180.0f));
    map.AddNPC (npc1_);

    yap::MapEvent* event = new yap::MapEvent ();
    event->AddBoundingBox (
      new yap::BoundingBox (
        yap::Vector2 (-30, -30), yap::Vector2 (60, 60), 0, 1));

    event->AddAction (
      new yap::AnyMapEventAction (yap::MapEventActionType::Leave,
        [this] (yap::MapEventArgs& args)
        {
          logger_.LogLine ("OUT");

          return true;
        }));

    event->AddAction (
      new yap::AnyMapEventAction (yap::MapEventActionType::Enter,
        [this] (yap::MapEventArgs& args)
        {
          logger_.LogLine ("IN");

          return true;
        }));

    event->AddAction (
      new yap::AnyMapEventAction (yap::MapEventActionType::In,
        [this] (yap::MapEventArgs& args)
        {
          logger_.LogLine ("UPDATE.....................");

          return true;
        }));

    npc1_->AddEvent (event);
  }

  void GameplayScreen::SetPlayer (Player* player)
  {
    player_ = player;

    moveController_.SetValue (player_->GetMaxVelocity ());

    cameraController_.SetTarget (*player);
    cameraController_.SetVelocityFactor (player->GetMaxVelocity ());

    /// @warning Tests.
    /// @todo Remove from here.
    player_->AddTriggerBoundingBox (
      new yap::BoundingBox (
        yap::Vector2 (-20, -20), yap::Vector2 (40, 40), 0, 1));
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
