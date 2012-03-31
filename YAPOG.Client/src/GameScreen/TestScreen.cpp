#include "GameScreen/TestScreen.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/ICamera.hpp"

TestScreen::TestScreen ()
  : yap::GameScreen ("Test")
  , textures_ ()
{
  for (int i = 0; i < 2000; ++i)
  {
    yap::Texture* texture = new yap::Texture ();
    texture->LoadFromFile ("boo.jpg");
    texture->Move (yap::Vector2 (i * 400.0f, 0.0f));
    texture->ChangeColor (sf::Color (128, 90, 128, 128));
    textures_.Add (texture);
  }
}

const yap::ScreenType& TestScreen::HandleRun (
  const yap::Time& dt,
  yap::IDrawingContext& context)
{
  yap::DebugLogger::Instance ().LogLine (1.0f / dt.GetValue ());

  context.GetCamera ("World").Move (
    yap::Vector2 (200.0f * dt.GetValue (), 0.0f));

  for (auto it : textures_)
    it->Draw (context);

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
