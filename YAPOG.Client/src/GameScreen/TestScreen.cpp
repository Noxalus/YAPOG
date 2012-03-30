#include "GameScreen/TestScreen.hpp"
#include "YAPOG/System/IO/Log/DebugLogger.hpp"

TestScreen::TestScreen ()
  : yap::GameScreen ("Test")
  , texture_ ()
{
  texture_.LoadFromFile ("boo.jpg");
}

const yap::ScreenType& TestScreen::HandleRun (
  const yap::Time& dt,
  yap::IDrawingContext& context)
{
  yap::DebugLogger::Instance ().LogLine (1.0f / dt.GetValue ());

  texture_.Draw (context);
  texture_.Move (yap::Vector2 (150.0f * dt.GetValue (), 0.0f));

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
