#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "Gui/PokemonMoveInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonMoveInfoWidget::PokemonMoveInfoWidget (const Pokemon& pokemon)
    : pokemon_ (pokemon)
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonMoveInfoBackground.png", true));
  }

  bool PokemonMoveInfoWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonMoveInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonMoveInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonMoveInfoWidget::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonMoveInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonMoveInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonMoveInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
