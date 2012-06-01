#ifndef YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp";
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp";

# include "Battle/BaseBattleWidget.hpp"

namespace ycl
{
  class PokemonBattleInfoWidget : public BaseBattleWidget
  {
    DISALLOW_COPY (PokemonBattleInfoWidget);

  public:
    PokemonBattleInfoWidget ();

    /// @name Getters.
    /// @{
    yap::Label& GetPokemonName ();
    /// @}

  private:
    /// @name Labels.
    /// @{
    yap::Label pokemonName_;
    /// @}

    /// @name Layouts.
    /// @{
    yap::HorizontalLayout horizontalLayout_;
    yap::VerticalLayout verticalLayout_;
    /// @}
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
