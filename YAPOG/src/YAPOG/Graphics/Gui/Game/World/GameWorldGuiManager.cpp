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
    , gameWorldWidgets_ ()
  {
  }

  GameWorldGuiManager::~GameWorldGuiManager ()
  {
  }

  void GameWorldGuiManager::SetWorldDrawingPolicy (
    const IWorldDrawingPolicy& worldDrawingPolicy)
  {
    worldDrawingPolicy_ = &worldDrawingPolicy;
  }

  void GameWorldGuiManager::AddGameWorldWidget (
    GameWorldWidget* gameWorldWidget)
  {
    gameWorldWidget->SetGameWorldRoot (*this);

    gameWorldWidgets_.Add (gameWorldWidget);
  }

  Vector2 GameWorldGuiManager::WorldPointToGuiPoint (
    const Vector3& worldPoint)
  {
    return guiCamera_.ToLocal (
      worldCamera_.ToLocal (
        worldDrawingPolicy_->ToScreenPosition (
          worldPoint)));
  }

  bool GameWorldGuiManager::IsFocusable () const
  {
    return false;
  }
} // namespace yap
