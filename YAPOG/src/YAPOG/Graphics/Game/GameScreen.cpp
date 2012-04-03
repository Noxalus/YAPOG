#include "YAPOG/Graphics/Game/GameScreen.hpp"
#include "YAPOG/Graphics/Gui/IGuiManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"

namespace yap
{
  GameScreen::GameScreen (const ScreenType& type)
    : nextScreen_ (type)
    , guiManager_ (nullptr)
    , type_ (type)
  {
  }

  GameScreen::~GameScreen ()
  {
    delete guiManager_;
    guiManager_ = nullptr;
  }

  void GameScreen::Init ()
  {
    HandleInit ();
  }

  void GameScreen::Activate ()
  {
    HandleActivate ();
  }

  void GameScreen::Deactivate ()
  {
    HandleDeactivate ();
  }

  const ScreenType& GameScreen::Run (const Time& dt, IDrawingContext& context)
  {
    nextScreen_ = HandleRun (dt, context);

    context.SetMode ("Gui");

    guiManager_->Update (dt);
    guiManager_->Draw (context);

    context.SetDefaultCamera ();

    return nextScreen_;
  }

  const IGuiManager& GameScreen::GetGuiManager () const
  {
    return *guiManager_;
  }

  IGuiManager& GameScreen::GetGuiManager ()
  {
    return *guiManager_;
  }

  const ScreenType& GameScreen::GetType () const
  {
    return type_;
  }

  bool GameScreen::OnEvent (const GuiEvent& guiEvent)
  {
    if (guiManager_->OnEvent (guiEvent))
      return true;

    return HandleOnEvent (guiEvent);
  }
} // namespace yap
