#include "YAPOG/Graphics/Gui/Game/World/GameWorldWidget.hpp"

namespace yap
{
  GameWorldWidget::GameWorldWidget ()
    : GameWidget ()
  {
  }

  GameWorldWidget::~GameWorldWidget ()
  {
  }

  void GameWorldWidget::SetGameWorldRoot (
    const GameWorldGuiManager& gameWorldRoot)
  {
    gameWorldRoot_ = &gameWorldRoot;
  }
} // namespace yap
