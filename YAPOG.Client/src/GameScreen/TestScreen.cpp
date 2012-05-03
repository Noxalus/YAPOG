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

    of.Create<Player> ("Player", yap::ID (1));

//  Player* pp = new Player (ID (1));
//  pp->AddSprite ("Inactive",

    map1 = of.Create<Map> ("Map", yap::ID (1));
    dl.LogLine ("MAP_ID=" + yap::StringHelper::ToString (map1->GetID ().GetValue ()));
    dl.LogLine ("MAP_NAME=" + map1->GetName ());
    dl.LogLine ("MAP_WIDTH=" + yap::StringHelper::ToString (map1->GetWidth ()));
    dl.LogLine ("MAP_HEIGHT=" + yap::StringHelper::ToString (map1->GetHeight ()));

    yap::Texture* t1 = of.Create<yap::Texture> ("Texture", yap::ID (1));
    dl.LogLine ("TEXTURE_ID=" + yap::StringHelper::ToString (t1->GetID ().GetValue ()));
    dl.LogLine ("TEXTURE_WIDTH=" + yap::StringHelper::ToString (t1->GetSize ().x));
    dl.LogLine ("TEXTURE_HEIGHT=" + yap::StringHelper::ToString (t1->GetSize ().y));

    ti1 = of.Create<yap::Tile> ("Tile", yap::ID (1));
    dl.LogLine ("TILE_ID=" + yap::StringHelper::ToString (ti1->GetID ().GetValue ()));

    ti1->Move (yap::Vector2 (200.0f, 200.0f));

    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Action,
        new yap::KeyboardGameInputEntry (yap::Key::Return)));
    gim.AddGameInput (
      new yap::GameInput (
        yap::GameInputType::Misc,
        new yap::KeyboardGameInputEntry (yap::Key::M)));
  }

  TestScreen::~TestScreen ()
  {
  }

  const yap::ScreenType& TestScreen::HandleRun (
    const yap::Time& dt,
    yap::IDrawingContext& context)
  {
    context.SetMode ("Background World");

    context.SetDefaultCamera ();

    context.SetMode ("World");

    map1->Draw (context);

    context.SetDefaultCamera ();

    context.GetCamera ("World").Move (
      yap::Vector2 (150.0f * dt.GetValue (), 60.0f * dt.GetValue ()));

    yap::DebugLogger::Instance().LogLine (1.0f/dt.GetValue());

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

    return false;
  }

  bool TestScreen::HandleOnPriorityEvent (const yap::GuiEvent& guiEvent)
  {
    return false;
  }
} // namespace ycl
