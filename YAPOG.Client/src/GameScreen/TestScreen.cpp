#include "GameScreen/TestScreen.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"

TestScreen::TestScreen ()
  : yap::GameScreen ("Test")
  , textures_ ()
{
  for (int i = 0; i < 200; ++i)
  {
    yap::Texture* texture = new yap::Texture ();
    texture->LoadFromFile ("boo.jpg");
    textures_.Add (texture);
  }
}

const yap::ScreenType& TestScreen::HandleRun (
  const yap::Time& dt,
  yap::IDrawingContext& context)
{
  yap::DebugLogger::Instance ().LogLine (1.0f / dt.GetValue ());

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
