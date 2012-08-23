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
#include "YAPOG/Game/Pokemon/Pokedex.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
#include "YAPOG/Game/Chat/GameMessage.hpp"
#include "YAPOG/Audio/AudioManager.hpp"
#include "YAPOG/Game/Battle/PlayerTrainer.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"
#include "YAPOG/Graphics/Game/Game.hpp"

#include "GameScreen/GameplayScreen.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/Map.hpp"
#include "Client/Session.hpp"
#include "Gui/GameGuiManager.hpp"
#include "Gui/GameMainMenu.hpp"
#include "Gui/ChatWidget.hpp"
#include "Gui/PokedexWidget.hpp"
#include "Gui/PokedexCompositeWidget.hpp"
#include "Gui/PokemonTeamWidget.hpp"

#include "Client/Session.hpp"
#include "Client/User.hpp"
#include "Battle/PlayerTrainer.hpp"
#include "Pokemon/Pokemon.hpp"
#include "Pokemon/PokemonTeam.hpp"
#include "Battle/PokemonFighter.hpp"
#include "Battle/PokemonFighterTeam.hpp"


namespace ycl
{
  const yap::ScreenType GameplayScreen::DEFAULT_NAME = "Gameplay";

  GameplayScreen::GameplayScreen (yap::ICamera& worldCamera)
    : BaseScreen (DEFAULT_NAME)
    , world_ ()
    , worldCamera_ (worldCamera)
    , cameraController_ (worldCamera_)
    , player_ (nullptr)
    , moveController_ ()
    , lastForce_ ()
    , fpsDisplayTimer_ ()
    , gameGuiManager_ (nullptr)
    , mainMenu_ (nullptr)
    , pokedex_ (nullptr)
    , pokemonTeamWidget_ (nullptr)
    , chat_ (nullptr)
    , fpsLabel_ (nullptr)
  {
  }

  GameplayScreen::~GameplayScreen ()
  {
    delete (chat_);
    chat_ = nullptr;
  }

  void GameplayScreen::HandleInit ()
  {
    BaseScreen::HandleInit ();

    session_.GetUser ().OnPlayerCreated += [this] (
      const User& sender,
      Player* args)
    {
      SetPlayer (args);
    };

    session_.GetUser ().OnPlayerWarped += [this] (
      const User& sender,
      Player& args)
    {
      HandleOnPlayerWarped ();
    };

    session_.GetUser ().OnMessageReceived += [this] (
      const User& sender,
      const yap::GameMessage& message)
    {
      chat_->AddMessage (message.GetContent ());
    };

    session_.GetUser ().OnBattleTriggered += [this] (
      const User& sender,
      const yap::EmptyEventArgs& args)
    {
      nextScreen_ = "Battle";
    };

    session_.GetUser ().OnPokemonTeamReceived += [this] (
      const User& sender,
      const yap::EmptyEventArgs& args)
    {
      // Team Manager Widget
      pokemonTeamWidget_ = new PokemonTeamWidget (
        session_.GetUser ().GetTrainer ().GetTeam ());
      pokemonTeamWidget_->Init ();
      pokemonTeamWidget_->Close ();
      gameGuiManager_->AddGameWidget ("PokemonTeam", pokemonTeamWidget_);
    };

    world_.OnMapChanged += [this] (
      const World& sender,
      const yap::ChangeEventArgs<Map*>& args)
    {
      SetCurrentMap (*args.Current);
    };

    session_.GetUser ().SetWorld (&world_);

    // Chat
    chat_ = new ChatWidget ();
    chat_->Init ();
    chat_->Close ();

    chat_->OnMessageSent +=
      [this] (ChatWidget& sender, yap::GameMessage& args)
    {
      session_.GetUser ().SendGameMessage (args);
    };

    gameGuiManager_->AddGameWidget ("Chat", chat_);


    /*
    team->AddPokemon (new Pokemon (yap::ID (2), 100, false));
    team->AddPokemon (new Pokemon (yap::ID (16), 32, true));

    PokemonFighterTeam* playerFighterTeam = new PokemonFighterTeam ();
    playerFighterTeam->AddPokemon (
    new PokemonFighter (team->GetPokemon (0), false));
    playerFighterTeam->AddPokemon (
    new PokemonFighter (team->GetPokemon (1), false));

    session_.GetUser ().GetTrainer ().SetTeam (playerFighterTeam);
    */

    // Pokedex
    yap::Pokedex* pokedexInfo = new yap::Pokedex ();

    for (int i = 1; i < 4; i++)
    {
      yap::PokemonInfo* pok = yap::ObjectFactory::Instance ().
        Create<yap::PokemonInfo> ("PokemonInfo", yap::ID (i));

      pokedexInfo->AddPokemon (pok);
      pokedexInfo->AddPokemonSeen (pok);
      pokedexInfo->AddPokemonCaught (pok);
    }

    pokedex_ = new PokedexWidget (pokedexInfo);
    pokedex_->Close ();
    pokedex_->Init ();

    gameGuiManager_->AddGameWidget ("Pokedex", pokedex_);

    // FPS
    fpsLabel_ = new yap::Label ();
    fpsLabel_->SetTextSize (18);

    guiManager_->AddChild (*fpsLabel_);
  }

  void GameplayScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    if (fpsDisplayTimer_.DelayIsComplete (yap::Time (0.5f), true))
      fpsLabel_->SetText (
      "FPS: " +
      yap::StringHelper::ToString<int> (1.0f / dt.GetValue ()));

    world_.Update (dt);

    cameraController_.Update (dt);

    UpdatePlayer (dt);

    world_.Draw (context);

    BaseScreen::HandleRun (dt, context);
  }

  bool GameplayScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
    case sf::Event::KeyPressed:

      switch (guiEvent.key.code)
      {
      case sf::Keyboard::B:
        /// @warning Battle Test
        nextScreen_ = "Battle";
        break;

      case sf::Keyboard::Space:

        if (player_ != nullptr && player_->IsActive ())
          break;

        gameGuiManager_->SetCurrentWidget ("Menu");
        yap::AudioManager::Instance ().PlayMusic ("BGM/SettingMenu.ogg");

        return true;

      case sf::Keyboard::C:

        if (player_ != nullptr && player_->IsActive ())
          break;

        gameGuiManager_->SetCurrentWidget ("Chat");

        return true;

      default: break;
      }

      break;

    case sf::Event::KeyReleased:

      switch (guiEvent.key.code)
      {
      default: break;
      }

    default: break;
    }

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

    if (gameInputManager_.GameInputIsActivated (
      yap::GameInputType::MapAction,
      guiEvent))
    {
      SendGameInput (yap::GameInputType::MapAction, true);
      return true;
    }

    if (gameInputManager_.GameInputIsDeactivated (
      yap::GameInputType::MapAction,
      guiEvent))
    {
      SendGameInput (yap::GameInputType::MapAction, false);
      return true;
    }

    return false;
  }

  void GameplayScreen::HandleActivate ()
  {
    yap::Game::CLEAR_COLOR = sf::Color::Black;

    yap::AudioManager::Instance ().PlayMusic ("BGM/City.ogg", false);
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
    SetPlayerName ();

    moveController_.SetValue (player_->GetMaxVelocity ());

    cameraController_.SetTarget (*player);
    cameraController_.SetVelocityFactor (player->GetMaxVelocity ());
  }

  void GameplayScreen::SetPlayerName ()
  {
    player_->SetName (session_.GetUser ().GetLogin ());

    mainMenu_ = new GameMainMenu ();
    mainMenu_->Init (player_->GetName ());

    mainMenu_->OnPokedexItemActivated += [this] (
      GameMainMenu& sender,
      const yap::EmptyEventArgs& args)
    {
      gameGuiManager_->SetCurrentWidget ("Pokedex");
    };
    mainMenu_->OnPokemonItemActivated += [this] (
      GameMainMenu& sender,
      const yap::EmptyEventArgs& args)
    {
      gameGuiManager_->SetCurrentWidget ("PokemonTeam");
    };

    gameGuiManager_->AddGameWidget ("Menu", mainMenu_);

    mainMenu_->Close ();
  }

  void GameplayScreen::UpdatePlayer (const yap::Time& dt)
  {
    if (player_ == nullptr)
      return;

    const yap::Vector2& force = moveController_.GetForce ();

    if (lastForce_ == force)
      return;

    SendApplyForce (force);

#if YAPOG_MOVE_PREDICTION
    // in case of client side move prediction player is moved
    // before server aknowledgement is received
    player_->ApplyForce (force);
#endif // YAPOG_MOVE_PREDICTION

    lastForce_ = force;
  }

  void GameplayScreen::HandleOnPlayerWarped ()
  {
    cameraController_.FocusTarget ();
  }

  void GameplayScreen::SendApplyForce (const yap::Vector2& force)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoApplyForce);

    packet.Write (force);

    session_.SendPacket (packet);
  }

  void GameplayScreen::SendGameInput (
    yap::GameInputType gameInputType,
    bool state)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoGameInput);

    packet.Write (static_cast<yap::Int16> (gameInputType));
    packet.Write (state);

    session_.SendPacket (packet);
  }

  void GameplayScreen::CreateGuiManager ()
  {
    gameGuiManager_ = new GameGuiManager ();

    guiManager_ = gameGuiManager_;
  }
} // namespace ycl
