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

TestScreen::TestScreen ()
  : yap::GameScreen ("Test")
  , textures_ ()
  , backTextures_ ()
  , anim1_ (1)
{
  yap::IFStream input ("../Content/Map/1.xml");
  yap::XmlReader xmlR (input, "Map");

  Map map (yap::ID (1));
  MapReader mapReader (map);

  xmlR.Accept (mapReader);

  yap::DebugLogger::Instance ()
    .LogLine ("MAP::ID=[" +
              yap::StringHelper::ToString (map.GetID ().GetValue ()) +
              "]")
    .LogLine ("MAP::NAME=[" + map.GetName () + "]");

  int animFlag = 0;

  for (int i = 0; i < 2000; ++i)
  {
    yap::Vector2 scaleFactor (0.7f, 0.7f);

    yap::Texture* texture = new yap::Texture ();
    texture->LoadFromFile ("boo.png");
//    texture->Move (yap::Vector2 (i * 400.0f, 0.0f));
    texture->Scale (scaleFactor);
    texture->ChangeColor (sf::Color (255, 90, 128, 128));
    textures_.Add (texture);

    if (animFlag++ < 2)
    {
      anim1_.AddFrame (new yap::Sprite (texture));
//      spr1_.SetTexture (texture);
    }

    texture = new yap::Texture ();
    texture->LoadFromFile ("boo.png");
//    texture->Move (yap::Vector2 (i * 400.0f + 200.0f, 0.0f));
    texture->ChangeColor (sf::Color (128, 255, 128, 128));
    texture->Scale (scaleFactor);
    backTextures_.Add (texture);

    if (animFlag++ < 2)
    {
      anim1_.AddFrame (new yap::Sprite (texture));
    }
  }

//  anim1_.Move (yap::Vector2 (100.0f, 100.0f));

  anim1_.ChangeState (yap::AnimatedSprite::PlayState::Loop);
//  anim1_.ChangeColor (sf::Color::Blue);
}

TestScreen::~TestScreen ()
{
/*  for (const auto& it : textures_)
    delete it;

  for (const auto& it : backTextures_)
  delete it;*/
}

const yap::ScreenType& TestScreen::HandleRun (
  const yap::Time& dt,
  yap::IDrawingContext& context)
{
//  yap::DebugLogger::Instance ().LogLine (1.0f / dt.GetValue ());

//  context.GetCamera ("Background World").Move (
//    yap::Vector2 (140.0f * dt.GetValue (), 0.0f));

  context.SetMode ("Background World");

//  for (auto it : backTextures_)
//    it->Draw (context);

  context.SetDefaultCamera ();

//  context.GetCamera ("World").Move (
//    yap::Vector2 (300.0f * dt.GetValue (), 0.0f));

//  for (auto it : textures_)
//    it->Draw (context);

  anim1_.Update (dt);
  anim1_.Draw (context);
//  spr1_.Draw (context);

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
  return false;
}
