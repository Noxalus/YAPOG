#include "YAPOG/Graphics/Game/Game.hpp"
#include "YAPOG/System/Time/Time.hpp"
#include "YAPOG/Graphics/Game/IGameScreenManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  Game::Game (const String& name)
    : screenManager_ (nullptr)
    , drawingContext_ (nullptr)
    , window_ (nullptr)
    , name_ (name)
    , isRunning_ (false)
    , timer_ ()
  {
  }

  Game::~Game ()
  {
    delete screenManager_;
    screenManager_ = nullptr;

    delete drawingContext_;
    drawingContext_ = nullptr;
  }

  void Game::Init ()
  {
    HandleInit ();
  }

  void Game::Launch ()
  {
    isRunning_ = true;

    while (isRunning_)
    {
      Time dt (timer_.GetCurrentTime ());
      timer_.Reset ();

      GuiEvent guiEvent;

      GameInputManager::Instance ().BeginUpdate ();

      while (window_->PollEvent (guiEvent))
      {
        GameInputManager::Instance ().Update (guiEvent);

        if (!screenManager_->OnEvent (guiEvent))
          HandleOnEvent (guiEvent);
      }

      GameInputManager::Instance ().EndUpdate ();

      window_->Clear ();

      HandleRun (dt, *drawingContext_);

      isRunning_ = window_->IsOpen ();

      window_->Display ();
    }
  }

  void Game::HandleRun (const Time& dt, IDrawingContext& context)
  {
    screenManager_->Run (dt, context);
  }
} // namespace yap
