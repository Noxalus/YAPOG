#include "YAPOG/Graphics/Game/GameScreenManager.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const String GameScreenManager::GAME_EXITED_EVENT_HANDLER_NAME =
    "GameExitedEventHandler";

  GameScreenManager::GameScreenManager ()
    : currentScreenType_ ()
    , currentScreen_ (nullptr)
    , screens_ ()
  {
  }

  GameScreenManager::~GameScreenManager ()
  {
    for (const auto& it : screens_)
      delete it.second;
  }

  bool GameScreenManager::OnEvent (const GuiEvent& guiEvent)
  {
    return currentScreen_->OnEvent (guiEvent);
  }

  bool GameScreenManager::OnPriorityEvent (const GuiEvent& guiEvent)
  {
    return currentScreen_->OnPriorityEvent (guiEvent);
  }

  void GameScreenManager::Init (const ScreenType& screenType)
  {
    for (const auto& it : screens_)
      it.second->Init ();

    SetCurrentScreen (screenType);
  }

  void GameScreenManager::AddGameScreen (IGameScreen* gameScreen)
  {
    gameScreen->OnGameExitedEvent ().AddHandler (
      GAME_EXITED_EVENT_HANDLER_NAME,
      [this] (IGameScreen& sender, const EmptyEventArgs& args)
      {
        OnGameExited (*this, EmptyEventArgs ());
      });

    screens_.Add (gameScreen->GetType (), gameScreen);
  }

  void GameScreenManager::RemoveGameScreen (const ScreenType& screenType)
  {
    IGameScreen& gameScreen = *screens_[screenType];

    gameScreen.OnGameExitedEvent ().RemoveHandler (
      GAME_EXITED_EVENT_HANDLER_NAME);

    screens_.Remove (screenType);
  }

  void GameScreenManager::SetCurrentScreen (const ScreenType& screenType)
  {
    if (currentScreenType_ == screenType)
      return;

    if (currentScreen_ != nullptr)
      currentScreen_->Deactivate ();

    currentScreenType_ = screenType;

    // If this screen doesn't exist
    if (!screens_.Contains (currentScreenType_))
    {
      YAPOG_THROW("This screen doesn't exist ! (Screen name: " +
        currentScreenType_ + ")");
    }

    currentScreen_ = screens_[currentScreenType_];

    currentScreen_->Activate ();
  }

  void GameScreenManager::NextFrame ()
  {
    currentScreen_->NextFrame ();
  }

  void GameScreenManager::Run (const Time& dt, IDrawingContext& context)
  {
    SetCurrentScreen (currentScreen_->Run (dt, context));
  }

  Event<IGameScreenManager&>& GameScreenManager::OnGameExitedEvent ()
  {
    return OnGameExited;
  }
} // namespace yap
