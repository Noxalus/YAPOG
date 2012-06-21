#include "YAPOG/Graphics/Game/GameScreenManager.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
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
} // namespace yap
