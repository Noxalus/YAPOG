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
#include "YAPOG/Graphics/Texture.hpp"
#include "YAPOG/Graphics/TextureReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/RegularAnimatedSprite.hpp"

#include "TestGame.hpp"
#include "GameScreen/LoadingScreen.hpp"
#include "GameScreen/UpdateScreen.hpp"
#include "GameScreen/OptionScreen.hpp"
#include "GameScreen/LoginScreen.hpp"
#include "GameScreen/GameplayScreen.hpp"
#include "GameScreen/BattleScreen.hpp"
#include "Client/Session.hpp"
#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/Player.hpp"
#include "World/Map/PlayerReader.hpp"
#include "World/Map/MapElement.hpp"
#include "World/Map/MapElementReader.hpp"

namespace ycl
{
  TestGame::TestGame (const yap::String& name)
    : yap::Game (name)
    , session_ (Session::Instance ())
    , contentManager_ (yap::ContentManager::Instance ())
    , objectFactory_ (yap::ObjectFactory::Instance ())
    , worldObjectStateFactory_ (yap::WorldObjectStateFactory::Instance ())
    , gameInputManager_ (yap::GameInputManager::Instance ())
    , logger_ (yap::DebugLogger::Instance ())
  {
  }

  TestGame::~TestGame ()
  {
  }

  void TestGame::HandleInit ()
  {
    InitRandom ();
#ifndef YAPOG_WIN
    InitContentManager (yap::Path ("../Content/"));
#else
    InitContentManager (yap::Path ("../../Content/"));
#endif // YAPOG_WIN
    InitObjectFactory ();
    InitGameInputManager ();
    InitWorldObjectStateFactory ();
    InitDrawingContext (yap::Vector2 (800.0f, 600.0f));
    InitScreenManager ();

    InitLoggerManager ();
  }

  bool TestGame::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    switch (guiEvent.type)
    {
      case yap::GuiEventType::Closed:

        window_->close ();

        return true;

      case yap::GuiEventType::KeyPressed:

        switch (guiEvent.key.code)
        {
          case yap::Key::Escape:

            window_->close ();

            return true;

          default:
            break;
        }

        break;

      default:
        break;
    }

    return false;
  }

  void TestGame::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    yap::Game::HandleRun (dt, context);

    session_.Refresh ();
  }

  void TestGame::HandleDispose ()
  {
    yap::Game::HandleDispose ();

    session_.Disconnect ();
  }

  void TestGame::InitRandom ()
  {
    yap::RandomHelper::Init (time (nullptr));
  }

  void TestGame::InitContentManager (const yap::Path& contentRootPath)
  {
    contentManager_.Init (contentRootPath);

    contentManager_.SetTexturePath (yap::Path ("Graphics"));
  }

  void TestGame::InitObjectFactory ()
  {
    objectFactory_.RegisterLoader (
      "AnimatedSprite",
      new yap::XmlObjectLoader<
        yap::RegularAnimatedSprite,
        yap::AnimatedSpriteReader> ());

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
      "Player",
      new yap::XmlObjectIDLoader<Player, PlayerReader> (
        yap::Path ("Player"),
        "Player"));

    objectFactory_.RegisterLoader (
      "RandomTileLayoutHandler",
      new yap::XmlObjectLoader<
        yap::RandomTileLayoutHandler,
        yap::RandomTileLayoutHandlerReader> ());

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
  }

  void TestGame::InitWorldObjectStateFactory ()
  {
    worldObjectStateFactory_.AddState ("Inactive", "Inactive");
    worldObjectStateFactory_.AddState ("Moving", "Moving");
  }

  void TestGame::InitGameInputManager ()
  {
    /// @todo Load inputs xml.

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

  void TestGame::InitDrawingContext (const yap::Vector2& resolution)
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

    window_ = &drawingContext->GetWindow ();
  }

  void TestGame::InitScreenManager ()
  {
    screenManager_ = new yap::GameScreenManager ();

    screenManager_->AddGameScreen (new LoadingScreen ());
    screenManager_->AddGameScreen (new UpdateScreen ());
    screenManager_->AddGameScreen (new OptionScreen ());
    screenManager_->AddGameScreen (new LoginScreen ());
    screenManager_->AddGameScreen (
      new GameplayScreen (
        drawingContext_->GetCamera (
          "World")));
    screenManager_->AddGameScreen (new BattleScreen ());

    screenManager_->Init ("Loading");
  }

  void TestGame::InitLoggerManager ()
  {
    logger_.AddMode (new yap::CountLoggerMode ());
    logger_.AddMode (new yap::TimeLoggerMode ());
  }
} // namespace ycl
