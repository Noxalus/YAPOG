#include <ctime>
#include "GameScreen/TestScreen.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/AnimatedSprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/AnimatedSpriteReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteSetReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/ComposedSprite.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputType.hpp"
#include "YAPOG/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInput.hpp"
#include "YAPOG/Content/ContentManager.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/String.hpp"
#include "YAPOG/Game/Factory/XmlObjectIDLoader.hpp"
#include "YAPOG/Game/Factory/XmlObjectLoader.hpp"
#include "YAPOG/Graphics/TextureReader.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Graphics/Game/Sprite/SpriteReader.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandlerReader.hpp"
#include "YAPOG/System/RandomHelper.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"
#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"
#include "YAPOG/Graphics/ProgressiveCameraController.hpp"
#include "YAPOG/Graphics/CenteredCameraController.hpp"
#include "YAPOG/Game/World/Map/Physics/CharacterMoveController.hpp"
#include "YAPOG/Game/World/Map/WorldObjectStateFactory.hpp"
#include "YAPOG/System/Network/ISocket.hpp"

#include "World/Map/Player.hpp"
#include "World/Map/PlayerReader.hpp"

///////////////////////////////
/// Just some ugly tests... ///
///////////////////////////////

const float MAX_VELOCITY = 250.0f;


yap::GameInputManager& gim = yap::GameInputManager::Instance ();
yap::ContentManager& cm = yap::ContentManager::Instance ();
yap::DebugLogger& dl = yap::DebugLogger::Instance ();

yap::ObjectFactory& of = yap::ObjectFactory::Instance ();

ycl::Map* map1;
ycl::Player* p1;
yap::CharacterMoveController cmc;

yap::CenteredCameraController* ccc = nullptr;
yap::ProgressiveCameraController* pcc = nullptr;

yap::WorldObjectStateFactory& wosf = yap::WorldObjectStateFactory::Instance ();
namespace ycl
{
  TestScreen::TestScreen ()
    : yap::GameScreen ("Test")
  {
    yap::RandomHelper::Init (time (nullptr));
    // loadable types are registered
    of.RegisterLoader (
      "Map",
      new yap::XmlObjectIDLoader<Map, MapReader> (
        yap::Path ("Map"), "Map"));
    of.RegisterLoader (
      "Texture",
      new yap::XmlObjectIDLoader<yap::Texture, yap::TextureReader> (
        yap::Path ("Texture"), "Texture"));
    of.RegisterLoader (
      "Tile",
      new yap::XmlObjectIDLoader<yap::Tile, yap::TileReader> (
        yap::Path ("Tile"), "Tile"));
    of.RegisterLoader (
      "Sprite",
      new yap::XmlObjectLoader<yap::Sprite, yap::SpriteReader> ());
    of.RegisterLoader (
      "RandomTileLayoutHandler",
      new yap::XmlObjectLoader<yap::RandomTileLayoutHandler,
                               yap::RandomTileLayoutHandlerReader> ());

    of.RegisterLoader (
      "StringSpriteSet",
      new yap::XmlObjectLoader<
        yap::SpriteSet<yap::String>,
        yap::SpriteSetReader<yap::String>> ());
    of.RegisterLoader (
      "DirectionSpriteSet",
      new yap::XmlObjectLoader<
        yap::SpriteSet<yap::Direction>,
        yap::SpriteSetReader<yap::Direction>> ());
    of.RegisterLoader (
      "AnimatedSprite",
      new yap::XmlObjectLoader<
        yap::RegularAnimatedSprite,
        yap::AnimatedSpriteReader> ());

    of.RegisterLoader (
      "Player",
      new yap::XmlObjectIDLoader<Player, PlayerReader> (
        yap::Path ("Player"),
        "Player"));

    wosf.AddState ("Inactive", "Inactive");
    wosf.AddState ("Moving", "Moving");

    p1 = of.Create<Player> ("Player", yap::ID (1));

    yap::BasicPhysicsCore* bpc = new yap::BasicPhysicsCore ();
    bpc->SetVelocityBounds (
      yap::Vector2 (),
      yap::Vector2 (MAX_VELOCITY, MAX_VELOCITY));
    p1->SetPhysicsCore (bpc);

    map1 = of.Get<Map> ("Map", yap::ID (1));

    map1->AddPlayer (p1);

    cmc.SetValue (MAX_VELOCITY);

    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Action,
        new yap::KeyboardGameInputEntry (yap::Key::Return)));
    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Misc,
        new yap::KeyboardGameInputEntry (yap::Key::M)));
    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Up,
        new yap::KeyboardGameInputEntry (yap::Key::Up)));
    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Down,
        new yap::KeyboardGameInputEntry (yap::Key::Down)));
    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Left,
        new yap::KeyboardGameInputEntry (yap::Key::Left)));
    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Right,
        new yap::KeyboardGameInputEntry (yap::Key::Right)));
  }

  TestScreen::~TestScreen ()
  {
  }

  const yap::ScreenType& TestScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    if (pcc == nullptr)
    {
      ccc = new yap::CenteredCameraController (context.GetCamera ("World"));
      ccc->SetTarget (*p1);
      ccc->SetBounds (yap::FloatRect (0.0f, 0.0f, 15000.0f, 15000.0f));

      pcc = new yap::ProgressiveCameraController (context.GetCamera ("World"));
      pcc->SetTarget (*p1);
      pcc->SetBounds (yap::FloatRect (0.0f, 0.0f, 15000.0f, 15000.0f));
      pcc->SetVelocityFactor (MAX_VELOCITY);
    }

    context.SetMode ("Background World");

    context.SetDefaultCamera ();

    context.SetMode ("World");

    p1->ApplyForce (cmc.GetForce ());

    map1->Update (dt);
//    ccc->Update (dt);
    pcc->Update (dt);


    map1->Draw (context);

    context.SetDefaultCamera ();

    yap::DebugLogger::Instance().LogLine (1.0f/dt.GetValue());

    return nextScreen_;
  }

  void TestScreen::HandleInit ()
  {
    yap::GameScreen::HandleInit ();
  }

  void TestScreen::HandleActivate ()
  {
  }

  void TestScreen::HandleDeactivate ()
  {
  }

  bool TestScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
    if (gim.GameInputIsActivated (yap::GameInputType::Down, guiEvent))
      cmc.EnableDirection (yap::Direction::South);
    else if (gim.GameInputIsActivated (yap::GameInputType::Up, guiEvent))
      cmc.EnableDirection (yap::Direction::North);
    else if (gim.GameInputIsActivated (yap::GameInputType::Left, guiEvent))
      cmc.EnableDirection (yap::Direction::West);
    else if (gim.GameInputIsActivated (yap::GameInputType::Right, guiEvent))
      cmc.EnableDirection (yap::Direction::East);

    if (gim.GameInputIsDeactivated (yap::GameInputType::Down, guiEvent))
      cmc.DisableDirection (yap::Direction::South);
    else if (gim.GameInputIsDeactivated (yap::GameInputType::Up, guiEvent))
      cmc.DisableDirection (yap::Direction::North);
    else if (gim.GameInputIsDeactivated (yap::GameInputType::Left, guiEvent))
      cmc.DisableDirection (yap::Direction::West);
    else if (gim.GameInputIsDeactivated (yap::GameInputType::Right, guiEvent))
      cmc.DisableDirection (yap::Direction::East);

    return false;
  }

  bool TestScreen::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
  {
    return false;
  }
} // namespace ycl
