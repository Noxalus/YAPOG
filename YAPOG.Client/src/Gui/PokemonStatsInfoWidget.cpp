#include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

#include "Gui/PokemonStatsInfoWidget.hpp"
#include "Pokemon/Pokemon.hpp"

namespace ycl
{
  PokemonStatsInfoWidget::PokemonStatsInfoWidget (const Pokemon& pokemon)
    : pokemon_ (pokemon)
  {
    SetBackground (*new yap::WidgetBackground (
      "Pictures/TeamManager/PokemonStatsInfoBackground.png", true));
  }

  bool PokemonStatsInfoWidget::IsFocusable () const
  {
    return false;
  }

  void PokemonStatsInfoWidget::HandleMove (const yap::Vector2& offset)
  {

  }
  void PokemonStatsInfoWidget::HandleScale (const yap::Vector2& factor)
  {

  }
  void PokemonStatsInfoWidget::HandleDraw (yap::IDrawingContext& offset)
  {

  }
  void PokemonStatsInfoWidget::HandleShow (bool isVisible)
  {
  }
  void PokemonStatsInfoWidget::HandleChangeColor (const sf::Color& color)
  {
  }
  void PokemonStatsInfoWidget::HandleUpdate (const yap::Time& dt)
  {
  }

} // namespace ycl
