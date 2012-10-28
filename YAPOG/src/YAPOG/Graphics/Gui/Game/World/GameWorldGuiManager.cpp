#include "YAPOG/Graphics/Gui/Game/World/GameWorldGuiManager.hpp"
#include "YAPOG/Graphics/ICamera.hpp"
#include "YAPOG/Graphics/Game/World/IWorldDrawingPolicy.hpp"

namespace yap
{
  GameWorldGuiManager::GameWorldGuiManager (
    const ICamera& guiCamera,
    const ICamera& worldCamera,
    const IWorldDrawingPolicy& worldDrawingPolicy)
    : GameWorldWidget ()
    , guiCamera_ (guiCamera)
    , worldCamera_ (worldCamera)
    , worldDrawingPolicy_ (&worldDrawingPolicy)
  {
  }

  GameWorldGuiManager::~GameWorldGuiManager ()
  {
  }

  void GameWorldGuiManager::Init ()
  {
    worldCamera_.OnMovedEvent ().AddHandler (
      "GameWorldGuiManager",
      [this] (ICamera& sender, const Vector2& args)
      {
        OnWorldCameraChanged (worldCamera_);
      });
  }

  void GameWorldGuiManager::SetWorldDrawingPolicy (
    const IWorldDrawingPolicy& worldDrawingPolicy)
  {
    worldDrawingPolicy_ = &worldDrawingPolicy;
  }

  Vector2 GameWorldGuiManager::WorldPointToGuiPoint (
    const Vector3& worldPoint) const
  {
    return guiCamera_.ToLocal (
      worldCamera_.ToLocal (
        worldDrawingPolicy_->ToScreenPosition (
          worldPoint)));
  }

  const GameWorldGuiManager& GameWorldGuiManager::GetGameWorldRoot () const
  {
    return *this;
  }
} // namespace yap
