#include "Battle/BaseBattleWidget.hpp"

namespace ycl
{
  BaseBattleWidget::BaseBattleWidget ()
  {
  }

  bool BaseBattleWidget::IsFocusable () const
  {
    return false;
  }

  void BaseBattleWidget::HandleMove (const yap::Vector2& offset)
  {
  }

  void BaseBattleWidget::HandleScale (const yap::Vector2& factor)
  {
  }

  void BaseBattleWidget::HandleDraw (yap::IDrawingContext& context)
  {
  }

  void BaseBattleWidget::HandleShow (bool isVisible)
  {
  }

  void BaseBattleWidget::HandleChangeColor (const sf::Color& color)
  {
  }

  void BaseBattleWidget::HandleUpdate (const yap::Time& dt)
  {
    int test = 0;
  }
}