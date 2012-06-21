#include "World/Map/PlayerInputManager.hpp"

namespace yse
{
  PlayerInputManager::PlayerInputManager ()
  {
  }

  PlayerInputManager::~PlayerInputManager ()
  {
  }

  bool PlayerInputManager::InputIsActive (
    yap::GameInputType gameInputType) const
  {
    return gameInputs_[gameInputType];
  }

  void PlayerInputManager::SetInputState (
    yap::GameInputType gameInputType,
    bool isActive)
  {
    gameInputs_[gameInputType] = isActive;
  }
} // namespace yse
