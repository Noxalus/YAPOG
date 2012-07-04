#include "YAPOG/Graphics/Game/Game.hpp"
#include "YAPOG/System/Time/Time.hpp"
#include "YAPOG/Graphics/Game/IGameScreenManager.hpp"
#include "YAPOG/Graphics/IDrawingContext.hpp"
#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"
#include "YAPOG/Graphics/Gui/GuiEvent.hpp"

namespace yap
{
  /// @WARNING TEMPORARY !
  /// @TODO REMOVE !
  sf::Color Game::CLEAR_COLOR = sf::Color::White;

  const sf::Color Game::DEFAULT_CLEAR_COLOR = sf::Color::Black;

  Game::Game (const String& name)
    : drawingContext_ (nullptr)
    , window_ (nullptr)
    , name_ (name)
    , screenManager_ (nullptr)
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

      window_->clear (CLEAR_COLOR);

      HandleRun (dt, *drawingContext_);

      isRunning_ &= window_->isOpen ();

      window_->display ();
    }

    Dispose ();
  }

  void Game::Dispose ()
  {
    HandleDispose ();
  }

  void Game::Stop ()
  {
    isRunning_ = false;
  }

  IGameScreenManager& Game::GetScreenManager ()
  {
    return *screenManager_;
  }

  void Game::SetScreenManager (IGameScreenManager* screenManager)
  {
    screenManager_ = screenManager;

    GetScreenManager ().OnGameExitedEvent () += [this] (
      IGameScreenManager& sender,
      const EmptyEventArgs& args)
    {
      Stop ();
    };
  }

  void Game::HandleRun (const Time& dt, IDrawingContext& context)
  {
    screenManager_->Run (dt, context);
  }

  void Game::HandleDispose ()
  {
  }
} // namespace yap
