#include "YAPOG/Graphics/Gui/GameInput/GameInputManager.hpp"

namespace yap
{
  GameInputManager::GameInputManager ()
    : gameInputs_ ()
  {
  }

  GameInputManager::~GameInputManager ()
  {
    for (const auto it : gameInputs_)
      delete it.second;
  }

  GameInputManager& GameInputManager::Instance ()
  {
    static GameInputManager instance;

    return instance;
  }

  void GameInputManager::BeginUpdate ()
  {
    for (const auto& it : gameInputs_)
      it.second->BeginUpdate ();
  }

  void GameInputManager::Update (const GuiEvent& guiEvent)
  {
    for (const auto& it : gameInputs_)
      it.second->Update (guiEvent);
  }

  void GameInputManager::EndUpdate ()
  {
    for (const auto& it : gameInputs_)
      it.second->EndUpdate ();
  }

  void GameInputManager::AddGameInput (GameInput* gameInput)
  {
    gameInputs_.Add (gameInput->GetType (), gameInput);
  }

  void GameInputManager::RemoveGameInput (GameInput* gameInput)
  {
    gameInputs_.Remove (gameInput->GetType ());
  }

  bool GameInputManager::GameInputIsActive (GameInputType gameInputType) const
  {
    return gameInputs_[gameInputType]->IsActive ();
  }

  bool GameInputManager::GameInputIsActivated (
    GameInputType gameInputType) const
  {
    return gameInputs_[gameInputType]->IsActivated ();
  }

  bool GameInputManager::GameInputIsDeactivated (
    GameInputType gameInputType) const
  {
    return gameInputs_[gameInputType]->IsDeactivated ();
  }

  bool GameInputManager::GameInputIsActive (
    GameInputType gameInputType,
    const GuiEvent& guiEvent) const
  {
    return gameInputs_[gameInputType]->IsActive (guiEvent);
  }

  bool GameInputManager::GameInputIsActivated (
    GameInputType gameInputType,
    const GuiEvent& guiEvent) const
  {
    return gameInputs_[gameInputType]->IsActivated (guiEvent);
  }

  bool GameInputManager::GameInputIsDeactivated (
    GameInputType gameInputType,
    const GuiEvent& guiEvent) const
  {
    return gameInputs_[gameInputType]->IsDeactivated (guiEvent);
  }
} // namespace yap
