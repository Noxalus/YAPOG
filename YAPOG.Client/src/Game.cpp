#include <ctime>

#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/XmlObjectLoader.hpp"
#include "YAPOG/Game/World/Map/WorldObjectStateFactory.hpp"
#include "YAPOG/Graphics/Camera.hpp"
#include "YAPOG/Graphics/DrawingContext.hpp"
#include "YAPOG/Graphics/Game/GameScreenManager.hpp"
#include "YAPOG/Graphics/Game/Sprite/AnimatedSpriteReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteSetReader.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp"
#include "YAPOG/System/IO/Log/CountLoggerMode.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/System/IO/Log/TimeLoggerMode.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteReader.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandlerReader.hpp"
#include "YAPOG/Graphics/Game/World/Map/SelectionTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/SelectionTileLayoutHandlerReader.hpp"
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/TextureReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/RegularAnimatedSprite.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfoReader.hpp"
#include "YAPOG/Game/Pokemon/PokemonInfo.hpp"
#include "YAPOG/Game/Pokemon/NatureInfoReader.hpp"
#include "YAPOG/Game/Pokemon/NatureInfo.hpp"
#include "YAPOG/Game/Pokemon/TypeInfoReader.hpp"
#include "YAPOG/Game/Pokemon/TypeInfo.hpp"
#include "YAPOG/Game/Pokemon/SkillInfoReader.hpp"
#include "YAPOG/Game/Pokemon/SkillInfo.hpp"
#include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"
#include "YAPOG/Game/World/Map/TeleporterReader.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeReader.hpp"
#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNodeReader.hpp"

#include "Client/Session.hpp"
#include "Game.hpp"
#include "Configuration/GameData.hpp"
#include "GameScreen/LoadingScreen.hpp"
#include "GameScreen/UpdateScreen.hpp"
#include "GameScreen/OptionScreen.hpp"
#include "GameScreen/LoginScreen.hpp"
#include "GameScreen/GameplayScreen.hpp"
#include "GameScreen/BattleScreen.hpp"
#include "GameScreen/MainMenuScreen.hpp"
#include "GameScreen/CreditScreen.hpp"
#include "GameScreen/RegistrationScreen.hpp"
#include "GameScreen/SplashScreen.hpp"
#include "Pokemon/PokemonInfo.hpp"
#include "Pokemon/PokemonInfoReader.hpp"
#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/PlayerReader.hpp"
#include "World/Map/MapElement.hpp"
#include "World/Map/MapElementReader.hpp"
#include "World/Map/NPC.hpp"
#include "World/Map/NPCReader.hpp"
#include "World/Map/Teleporter.hpp"
#include "World/Map/DestructibleObject.hpp"
#include "World/Map/DestructibleObjectReader.hpp"
#include "World/Map/OpenBattleSpawnerArea.hpp"
#include "World/Map/OpenBattleSpawnerAreaReader.hpp"
#include "Battle/PlayerTrainer.hpp"
#include "Pokemon/PokemonTeam.hpp"

namespace ycl
{
  const yap::Vector2 Game::SCREEN_SIZE = yap::Vector2 (800, 600);

  Game::Game (const yap::String& name)
    : yap::Game (name)
    , session_ (Session::Instance ())
    , contentManager_ (yap::ContentManager::Instance ())
    , objectFactory_ (yap::ObjectFactory::Instance ())
    , worldObjectStateFactory_ (yap::WorldObjectStateFactory::Instance ())
    , gameInputManager_ (yap::GameInputManager::Instance ())
    , logger_ (yap::DebugLogger::Instance ())
  {
  }

  Game::~Game ()
  {
  }

  void Game::HandleInit ()
  {
    InitRandom ();

    InitContentManager (yap::Path (GameData::ContentPath ()));

    InitObjectFactory ();
    InitGameInputManager ();
    InitWorldObjectStateFactory ();
    InitDrawingContext (GameData::WindowSize ());
    InitScreenManager ();

    InitLoggerManager ();
  }

  bool Game::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
      case yap::GuiEventType::Closed:

        window_->close ();

        return true;

      default:
        break;
    }

    return yap::Game::HandleOnEvent (guiEvent);
  }

  void Game::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    session_.Refresh ();

    // Update player's game time
    session_.GetUser ().UpdatePlayTime (dt);

    yap::Game::HandleRun (dt, context);
  }

  void Game::HandleDispose ()
  {
    yap::Game::HandleDispose ();

    session_.Disconnect ();
  }

  void Game::InitRandom ()
  {
    yap::RandomHelper::Init (time (nullptr));
  }

  void Game::InitContentManager (const yap::Path& contentRootPath)
  {
    contentManager_.Init (contentRootPath);

    contentManager_.SetTexturePath (yap::Path (GameData::TexturePath ()));
    contentManager_.SetFontPath (yap::Path (GameData::FontPath ()));
    contentManager_.SetMusicPath (yap::Path (GameData::MusicPath ()));
    contentManager_.SetSoundBufferPath (yap::Path (GameData::SoundPath ()));
  }

  void Game::InitObjectFactory ()
  {
    objectFactory_.RegisterLoader (
      "AnimatedSprite",
      new yap::XmlObjectLoader<
        yap::RegularAnimatedSprite,
        yap::AnimatedSpriteReader> ());

    objectFactory_.RegisterLoader (
      "DestructibleObject",
      new yap::XmlObjectIDLoader<
        DestructibleObject,
        DestructibleObjectReader> (
          yap::Path ("DestructibleObject"),
          "DestructibleObject"));

    objectFactory_.RegisterLoader (
      "DialogNode",
      new yap::XmlObjectLoader<
        yap::DialogNode,
        yap::DialogNodeReader> ());

    objectFactory_.RegisterLoader (
      "ResponseHandlerDialogNode",
      new yap::XmlObjectLoader<
        yap::ResponseHandlerDialogNode,
        yap::ResponseHandlerDialogNodeReader> ());

    objectFactory_.RegisterLoader (
      "DirectionSpriteSet",
      new yap::XmlObjectLoader<
      yap::SpriteSet<yap::Direction>,
      yap::SpriteSetReader<yap::Direction>> ());

    objectFactory_.RegisterLoader (
      "Map",
      new yap::XmlObjectIDLoader<Map, MapReader> (
        yap::Path ("Map"),
        "Map"));

    objectFactory_.RegisterLoader (
      "MapElement",
      new yap::XmlObjectIDLoader<MapElement, MapElementReader> (
        yap::Path ("MapElement"),
        "MapElement"));

    objectFactory_.RegisterLoader (
      "NPC",
      new yap::XmlObjectIDLoader<NPC, NPCReader> (
        yap::Path ("NPC"),
        "NPC"));

    objectFactory_.RegisterLoader (
      "OpenBattleSpawnerArea",
      new yap::XmlObjectIDLoader<
      OpenBattleSpawnerArea,
      OpenBattleSpawnerAreaReader> (
        yap::Path ("OpenBattleSpawnerArea"),
        "OpenBattleSpawnerArea"));

    objectFactory_.RegisterLoader (
      "Player",
      new yap::XmlObjectIDLoader<Player, PlayerReader> (
        yap::Path ("Player"),
        "Player"));

    objectFactory_.RegisterLoader (
      "Teleporter",
      new yap::XmlObjectIDLoader<Teleporter, yap::TeleporterReader> (
        yap::Path ("Teleporter"),
        "Teleporter"));

    objectFactory_.RegisterLoader (
      "RandomTileLayoutHandler",
      new yap::XmlObjectLoader<
      yap::RandomTileLayoutHandler,
      yap::RandomTileLayoutHandlerReader> ());

    objectFactory_.RegisterLoader (
      "SelectionTileLayoutHandler",
      new yap::XmlObjectLoader<
      yap::SelectionTileLayoutHandler,
      yap::SelectionTileLayoutHandlerReader> ());

    objectFactory_.RegisterLoader (
      "Sprite",
      new yap::XmlObjectLoader<yap::Sprite, yap::SpriteReader> ());

    objectFactory_.RegisterLoader (
      "StringSpriteSet",
      new yap::XmlObjectLoader<
      yap::SpriteSet<yap::String>,
      yap::SpriteSetReader<yap::String>> ());

    objectFactory_.RegisterLoader (
      "Texture",
      new yap::XmlObjectIDLoader<yap::Texture, yap::TextureReader> (
        yap::Path ("Texture"),
        "Texture"));

    objectFactory_.RegisterLoader (
      "Tile",
      new yap::XmlObjectIDLoader<yap::Tile, yap::TileReader> (
        yap::Path ("Tile"),
        "Tile"));

    objectFactory_.RegisterLoader (
      "PokemonInfo",
      new yap::XmlObjectIDLoader<PokemonInfo, PokemonInfoReader> (
        yap::Path ("Pokemon/Pokemon"),
        "PokemonInfo"));

    objectFactory_.RegisterLoader (
      "NatureInfo",
      new yap::XmlObjectIDLoader<yap::NatureInfo, yap::NatureInfoReader> (
        yap::Path ("Pokemon/Nature"),
        "Nature"));

    objectFactory_.RegisterLoader (
      "TypeInfo",
      new yap::XmlObjectIDLoader<yap::TypeInfo, yap::TypeInfoReader> (
        yap::Path ("Pokemon/Types"),
        "Type"));

    objectFactory_.RegisterLoader (
      "SkillInfo",
      new yap::XmlObjectIDLoader<yap::SkillInfo, yap::SkillInfoReader> (
        yap::Path ("Pokemon/Skills"),
        "Skill"));
  }

  void Game::InitWorldObjectStateFactory ()
  {
    worldObjectStateFactory_.AddState ("Inactive", "Inactive");
    worldObjectStateFactory_.AddState ("Moving", "Moving");
    worldObjectStateFactory_.AddState ("Listening", "Listening");
    worldObjectStateFactory_.AddState ("Talking", "Talking");
  }

  void Game::InitGameInputManager ()
  {
    /// @todo Load `inputs' xml.

    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::MapAction,
        new yap::KeyboardGameInputEntry (yap::Key::A)));
    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Action,
        new yap::KeyboardGameInputEntry (yap::Key::Return)));
    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Misc,
        new yap::KeyboardGameInputEntry (yap::Key::M)));
    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Up,
        new yap::KeyboardGameInputEntry (yap::Key::Up)));
    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Down,
        new yap::KeyboardGameInputEntry (yap::Key::Down)));
    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Left,
        new yap::KeyboardGameInputEntry (yap::Key::Left)));
    gameInputManager_.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Right,
        new yap::KeyboardGameInputEntry (yap::Key::Right)));
  }

  void Game::InitDrawingContext (const yap::Vector2& resolution)
  {
    yap::DrawingContext* drawingContext = new yap::DrawingContext (
      resolution,
      name_);

    drawingContext_ = drawingContext;

    drawingContext_->AddCamera (
      "World",
      new yap::Camera (yap::Vector2 (),  resolution));

    drawingContext_->AddCamera (
      "Background World",
      new yap::Camera (yap::Vector2 (),  resolution));

    drawingContext_->AddCamera (
      "Gui", new yap::Camera (yap::Vector2 (), resolution));

    drawingContext_->AddCamera (
      "Battle", new yap::Camera (yap::Vector2 (), resolution));

    window_ = &drawingContext->GetWindow ();
  }

  void Game::InitScreenManager ()
  {
    SetScreenManager (new yap::GameScreenManager ());

    GetScreenManager ().AddGameScreen (new LoadingScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new UpdateScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new OptionScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new LoginScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new GameplayScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new BattleScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new MainMenuScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (
      new RegistrationScreen (
        *drawingContext_));
    GetScreenManager ().AddGameScreen (new SplashScreen (*drawingContext_));
    GetScreenManager ().AddGameScreen (new CreditScreen (*drawingContext_));

    GetScreenManager ().Init ("Loading");
  }

  void Game::InitLoggerManager ()
  {
    logger_.AddMode (new yap::CountLoggerMode ());
    logger_.AddMode (new yap::TimeLoggerMode ());
  }
} // namespace ycl
