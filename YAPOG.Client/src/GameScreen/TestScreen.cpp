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

#include "World/Map/Player.hpp"
#include "World/Map/PlayerReader.hpp"

///////////////////////////////
/// Just some ugly tests... ///
///////////////////////////////

//DirectionalSpriteSet dss1;
yap::GameInputManager& gim = yap::GameInputManager::Instance ();
yap::ContentManager& cm = yap::ContentManager::Instance ();
yap::DebugLogger& dl = yap::DebugLogger::Instance ();

yap::ObjectFactory& of = yap::ObjectFactory::Instance ();

yap::Tile* ti1;
ycl::Map* map1;
ycl::Player* p1;

yap::ProgressiveCameraController* pcc = nullptr;
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

    p1 = of.Create<Player> ("Player", yap::ID (1));

    yap::BasicPhysicsCore* bpc = new yap::BasicPhysicsCore ();
    p1->SetPhysicsCore (bpc);

    map1 = of.Create<Map> ("Map", yap::ID (1));
    dl.LogLine (
      "MAP_ID=" + yap::StringHelper::ToString (map1->GetID ().GetValue ()));
    dl.LogLine ("MAP_NAME=" + map1->GetName ());
    dl.LogLine (
      "MAP_WIDTH=" + yap::StringHelper::ToString (map1->GetWidth ()));
    dl.LogLine (
      "MAP_HEIGHT=" + yap::StringHelper::ToString (map1->GetHeight ()));

    yap::Texture* t1 = of.Create<yap::Texture> ("Texture", yap::ID (1));
    dl.LogLine (
      "TEXTURE_ID=" + yap::StringHelper::ToString (t1->GetID ().GetValue ()));
    dl.LogLine (
      "TEXTURE_WIDTH=" + yap::StringHelper::ToString (t1->GetSize ().x));
    dl.LogLine (
      "TEXTURE_HEIGHT=" + yap::StringHelper::ToString (t1->GetSize ().y));

    ti1 = of.Create<yap::Tile> ("Tile", yap::ID (1));
    dl.LogLine (
      "TILE_ID=" + yap::StringHelper::ToString (ti1->GetID ().GetValue ()));

    ti1->Move (yap::Vector2 (200.0f, 200.0f));

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
      pcc = new yap::ProgressiveCameraController (context.GetCamera ("World"));
      pcc->SetTarget (*p1);
      pcc->SetBounds (yap::FloatRect (0.0f, 0.0f, 5000.0f, 5000.0f));
    }

    const float forceValue = 100000000.0f;
    if (gim.GameInputIsActive (yap::GameInputType::Down))
    {
      p1->ApplyForce (yap::Vector2 (0.0f, forceValue));
//      p1->TryChangeState ("Walking");
    }
    else if (gim.GameInputIsActive (yap::GameInputType::Up))
      p1->ApplyForce (yap::Vector2 (0.0f, -forceValue));
    else if (gim.GameInputIsActive (yap::GameInputType::Left))
      p1->ApplyForce (yap::Vector2 (-forceValue, 0.0f));
    else if (gim.GameInputIsActive (yap::GameInputType::Right))
      p1->ApplyForce (yap::Vector2 (forceValue, 0.0f));

    context.SetMode ("Background World");

    context.SetDefaultCamera ();

    context.SetMode ("World");

    p1->Update (dt);

    const yap::Vector2& p1Move = p1->GetMove ();

    dl.LogLine ("( " + yap::StringHelper::ToString (p1->GetMove ().x) + ", " +
                yap::StringHelper::ToString (p1->GetMove ().y) + " )");
    p1->Move (p1Move);

    pcc->Update (dt);

    map1->Draw (context);
    p1->Draw (context);

    context.SetDefaultCamera ();

//    context.GetCamera ("World").Move (
//      yap::Vector2 (150.0f * dt.GetValue (), 60.0f * dt.GetValue ()));

//    yap::DebugLogger::Instance().LogLine (1.0f/dt.GetValue());

    return nextScreen_;
  }

  void TestScreen::HandleInit ()
  {
    guiManager_ = new yap::GuiManager ();
  }

  void TestScreen::HandleActivate ()
  {
  }

  void TestScreen::HandleDeactivate ()
  {
  }

  bool TestScreen::HandleOnEvent (const yap::GuiEvent& guiEvent)
  {
//  if (gim.GameInputIsActivated (yap::GameInputType::Action, guiEvent));
//    dss1.SetCurrentSprite (yap::Direction::North);

//  if (gim.GameInputIsActivated (yap::GameInputType::Misc, guiEvent));
//    dss1.SetCurrentSprite (yap::Direction::South);

//    const float forceValue = 100.0f;

//    if (gim.GameInputIsActive (yap::GameInputType::Down, guiEvent))
//    {
//      dl.LogLine ("FORCE APPLIED");
//      p1->ApplyForce (yap::Vector2 (0.0f, forceValue));
//      return true;
//    }

    return false;
  }

  bool TestScreen::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
  {
    return false;
  }
} // namespace ycl
