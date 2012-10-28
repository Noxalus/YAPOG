#include "World/Map/PlayerInputManager.hpp"

namespace yse
{
  PlayerInputManager::PlayerInputManager ()
    : gameInputs_ ()
  {
    AddInput (yap::GameInputType::MapAction);
  }

  PlayerInputManager::~PlayerInputManager ()
  {
  }

  bool PlayerInputManager::InputIsActivated (
    yap::GameInputType gameInputType) const
  {
    return GetInputState (gameInputType) == Entry::State::Activated;
  }

  bool PlayerInputManager::InputIsDeactivated (
    yap::GameInputType gameInputType) const
  {
    return GetInputState (gameInputType) == Entry::State::Deactivated;
  }

  bool PlayerInputManager::InputIsActive (
    yap::GameInputType gameInputType) const
  {
    Entry::State gameInputState = GetInputState (gameInputType);

    return
      gameInputState == Entry::State::Activated ||
      gameInputState == Entry::State::Active;
  }

  void PlayerInputManager::SetInputState (
    yap::GameInputType gameInputType,
    bool isActive)
  {
    gameInputs_[gameInputType].Activate (isActive);
  }

  void PlayerInputManager::Refresh ()
  {
    for (auto& gameInputTypeEntryPair : gameInputs_)
      gameInputTypeEntryPair.second.Refresh ();
  }

  void PlayerInputManager::AddInput (yap::GameInputType gameInputType)
  {
    gameInputs_.Add (gameInputType, Entry ());
  }

  PlayerInputManager::Entry::State
  PlayerInputManager::GetInputState (yap::GameInputType gameInputType) const
  {
    return gameInputs_[gameInputType].GetState ();
  }

  const PlayerInputManager::Entry::State
  PlayerInputManager::Entry::DEFAULT_STATE =
    PlayerInputManager::Entry::State::Inactive;

  PlayerInputManager::Entry::Entry ()
    : currentState_ (DEFAULT_STATE)
    , newState_ (currentState_)
    , isRefreshed_ (true)
  {
  }

  PlayerInputManager::Entry::State PlayerInputManager::Entry::GetState () const
  {
    return currentState_;
  }

  void PlayerInputManager::Entry::Activate (bool isActive)
  {
    isRefreshed_ = false;

    newState_ =
      isActive ? Entry::State::Activated : Entry::State::Deactivated;
  }

  void PlayerInputManager::Entry::Refresh ()
  {
    if (isRefreshed_)
      return;

    if (currentState_ != newState_)
    {
      currentState_ = newState_;

      return;
    }

    isRefreshed_ = true;

    switch (currentState_)
    {
      case Entry::State::Activated:

        currentState_ = Entry::State::Active;

        break;

      case Entry::State::Deactivated:

        currentState_ = Entry::State::Inactive;

        break;

      default: break;
    }
  }
} // namespace yse
