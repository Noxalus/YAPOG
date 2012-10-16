#include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"

namespace yap
{
  GameWorldWidget::GameWorldWidget ()
    : GameWidget ()
    , gameWorldParent_ (nullptr)
    , gameWorldWidgets_ ()
  {
  }

  GameWorldWidget::~GameWorldWidget ()
  {
  }

  void GameWorldWidget::AddGameWorldWidget (
    GameWorldWidget* gameWorldWidget)
  {
    gameWorldWidget->SetGameWorldParent (*this);

    gameWorldWidgets_.Add (gameWorldWidget);

    AddChild (*gameWorldWidget);
  }

  void GameWorldWidget::RemoveGameWorldWidget (
    GameWorldWidget* gameWorldWidget)
  {
    gameWorldWidgets_.Remove (gameWorldWidget);

    RemoveChild (*gameWorldWidget);
  }

  void GameWorldWidget::SetGameWorldParent (
    const GameWorldWidget& gameWorldParent)
  {
    gameWorldParent_ = &gameWorldParent;
  }

  bool GameWorldWidget::IsFocusable () const
  {
    return false;
  }

  void GameWorldWidget::OnWorldCameraChanged (const ICamera& worldCamera)
  {
    for (auto child : gameWorldWidgets_)
      child->OnWorldCameraChanged (worldCamera);

    HandleOnWorldCameraChanged (worldCamera);
  }

  void GameWorldWidget::HandleOnWorldCameraChanged (const ICamera& worldCamera)
  {
  }

  const GameWorldGuiManager& GameWorldWidget::GetGameWorldRoot () const
  {
    return gameWorldParent_->GetGameWorldRoot ();
  }
} // namespace yap
