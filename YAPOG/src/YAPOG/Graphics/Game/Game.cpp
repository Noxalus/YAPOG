#include "YAPOG/Graphics/Game/Game.hpp"
#include "YAPOG/System/Time/Time.hpp"
#include "YAPOG/Graphics/Game/IGameScreenManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  const sf::Color Game::DEFAULT_CLEAR_COLOR = sf::Color::White;

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

      screenManager_->NextFrame ();

      GuiEvent guiEvent;

      GameInputManager::Instance ().BeginUpdate ();

      while (window_->pollEvent (guiEvent))
      {
        GameInputManager::Instance ().Update (guiEvent);

        if (screenManager_->OnPriorityEvent (guiEvent))
          continue;

        if (screenManager_->OnEvent (guiEvent))
          continue;

        HandleOnEvent (guiEvent);
      }

      GameInputManager::Instance ().EndUpdate ();

      window_->clear (DEFAULT_CLEAR_COLOR);

      HandleRun (dt, *drawingContext_);

      isRunning_ = window_->isOpen ();

      window_->display ();
    }

    Dispose ();
  }

  void Game::Dispose ()
  {
    HandleDispose ();
  }

  void Game::HandleRun (const Time& dt, IDrawingContext& context)
  {
    screenManager_->Run (dt, context);
  }

  void Game::HandleDispose ()
  {
  }
} // namespace yap
