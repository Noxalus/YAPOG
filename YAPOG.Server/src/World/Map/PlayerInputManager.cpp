#include "World/Map/PlayerInputManager.hpp"

namespace yse
{
  PlayerInputManager::PlayerInputManager ()
    : gameInputs_ ()
  {
    gameInputs_.Add (yap::GameInputType::MapAction, false);
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
