#include "YAPOG/Graphics/Game/GameScreen.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/GuiManager.hpp"

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

  const GuiManager& GameScreen::GetGuiManager () const
  {
    return *guiManager_;
  }

  GuiManager& GameScreen::GetGuiManager ()
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

  bool GameScreen::OnPriorityEvent (const GuiEvent& guiEvent)
  {
    if (HandleOnPriorityEvent (guiEvent))
      return true;

    return guiManager_->OnPriorityEvent (guiEvent);
  }

  void GameScreen::CreateGuiManager ()
  {
    guiManager_ = new GuiManager ();
  }

  const ScreenType& GameScreen::HandleRun (
    const Time& dt,
    IDrawingContext& context)
  {
    return nextScreen_;
  }

  void GameScreen::HandleInit ()
  {
    CreateGuiManager ();
  }

  void GameScreen::HandleActivate ()
  {
  }

  void GameScreen::HandleDeactivate ()
  {
  }

  bool GameScreen::HandleOnEvent (const GuiEvent& guiEvent)
  {
    return false;
  }

  bool GameScreen::HandleOnPriorityEvent (const GuiEvent& guiEvent)
  {
    return false;
  }
} // namespace yap
