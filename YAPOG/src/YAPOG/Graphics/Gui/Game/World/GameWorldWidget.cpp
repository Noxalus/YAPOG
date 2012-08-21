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

  void GameWorldWidget::SetGameWorldParent (
    const GameWorldWidget& gameWorldParent)
  {
    gameWorldParent_ = &gameWorldParent;

    HandleSetGameWorldParent (gameWorldParent);
  }

  bool GameWorldWidget::IsFocusable () const
  {
    return false;
  }

  const GameWorldGuiManager& GameWorldWidget::GetGameWorldRoot () const
  {
    return gameWorldParent_->GetGameWorldRoot ();
  }

  void GameWorldWidget::HandleSetGameWorldParent (
    const GameWorldWidget& gameWorldParent)
  {
  }
} // namespace yap
