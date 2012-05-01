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
#include "YAPOG/Graphics/Game/Sprite/SpriteSet.hpp"
#include "YAPOG/Graphics/Game/Sprite/DirectionalSpriteSet.hpp"
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

using namespace yap;

//DirectionalSpriteSet dss1;
GameInputManager& gim = yap::GameInputManager::Instance ();
ContentManager& cm = ContentManager::Instance ();
DebugLogger& dl = DebugLogger::Instance ();

ObjectFactory& of = ObjectFactory::Instance ();

Tile* ti1;
::Map* map1;
TestScreen::TestScreen ()
  : yap::GameScreen ("Test")
{
  RandomHelper::Init (time (nullptr));
  // loadable types are registered
  of.RegisterLoader ("Map", new XmlObjectIDLoader< ::Map, ::MapReader> (
                       Path ("Map"), "Map"));
  of.RegisterLoader ("Texture", new XmlObjectIDLoader<Texture, TextureReader> (
                       Path ("Texture"), "Texture"));
  of.RegisterLoader ("Tile", new XmlObjectIDLoader<Tile, TileReader> (
                       Path ("Tile"), "Tile"));
  of.RegisterLoader ("Sprite", new XmlObjectLoader<Sprite, SpriteReader> ());
  of.RegisterLoader (
    "RandomTileLayoutHandler",
    new XmlObjectLoader<RandomTileLayoutHandler,
                        RandomTileLayoutHandlerReader> ());

  /*of.RegisterLoader (
    "Player",
    new XmlObjectIDLoader<Player, PlayerReader> (
      Path ("Player"),
      "Player"));*/
//  of.Create<Player> ("Player", yap::ID (1));


//  Player* pp = new Player (ID (1));
//  pp->AddSprite ("Inactive",








  float ff = RandomHelper::GetNext (2.f, 3.f);
  dl.LogLine (StringHelper::ToString (ff));

  int ii = RandomHelper::GetNext (2, 3);
  dl.LogLine (StringHelper::ToString (ii));

  map1 = of.Create< ::Map> ("Map", yap::ID (1));
  dl.LogLine ("MAP_ID=" + StringHelper::ToString (map1->GetID ().GetValue ()));
  dl.LogLine ("MAP_NAME=" + map1->GetName ());
  dl.LogLine ("MAP_WIDTH=" + StringHelper::ToString (map1->GetWidth ()));
  dl.LogLine ("MAP_HEIGHT=" + StringHelper::ToString (map1->GetHeight ()));

  Texture* t1 = of.Create<Texture> ("Texture", yap::ID (1));
  dl.LogLine ("TEXTURE_ID=" + StringHelper::ToString (t1->GetID ().GetValue ()));
  dl.LogLine ("TEXTURE_WIDTH=" + StringHelper::ToString (t1->GetSize ().x));
  dl.LogLine ("TEXTURE_HEIGHT=" + StringHelper::ToString (t1->GetSize ().y));

  ti1 = of.Create<Tile> ("Tile", yap::ID (1));
  dl.LogLine ("TILE_ID=" + StringHelper::ToString (ti1->GetID ().GetValue ()));

  ti1->Move (yap::Vector2 (200.0f, 200.0f));

  gim.AddGameInput (
    new GameInput (
      GameInputType::Action,
      new KeyboardGameInputEntry (Key::Return)));
  gim.AddGameInput (
    new GameInput (
      GameInputType::Misc,
      new KeyboardGameInputEntry (Key::M)));
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

  DebugLogger::Instance().LogLine (1.0f/dt.GetValue());

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
