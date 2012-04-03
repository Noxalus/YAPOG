#include "YAPOG/Graphics/Game/GameScreenManager.hpp"

namespace yap
{
  GameScreenManager::GameScreenManager ()
    : currentScreenType_ ()
    , currentScreen_ ()
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

  void GameScreenManager::Init (const ScreenType& screenType)
  {
    for (const auto& it : screens_)
      it.second->Init ();

    SetCurrentScreen (screenType);
  }

  void GameScreenManager::AddGameScreen (IGameScreen* gameScreen)
  {
    screens_.Add (gameScreen->GetType (), gameScreen);
  }

  void GameScreenManager::RemoveGameScreen (const ScreenType& screenType)
  {
    screens_.Remove (screenType);
  }

  void GameScreenManager::SetCurrentScreen (const ScreenType& screenType)
  {
    if (currentScreenType_ == screenType)
      return;

    currentScreenType_ = screenType;

    currentScreen_ = screens_[currentScreenType_];
  }

  void GameScreenManager::Run (const Time& dt, IDrawingContext& context)
  {
    currentScreen_->Run (dt, context);
  }
} // namespace yap
