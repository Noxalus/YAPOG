#ifndef YAPOG_CLIENT_BATTLEINTERFACE_HPP
# define YAPOG_CLIENT_BATTLEINTERFACE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace yap
{
  class WidgetDialogBox;
} // namespace yap

namespace ycl
{
  class BattleBackgroundWidget;
  class PokemonBattleInfoWidget;
  class OpponentBattleInfoWidget;

  class BattleInterface : public BaseBattleWidget
  {
  public:
    BattleInterface ();

    /// @name Getters.
    /// @{
    yap::WidgetDialogBox& GetBattleInfoDialogBox ();
    PokemonBattleInfoWidget& GetPokemonInfoWidget ();
    OpponentBattleInfoWidget& GetOpponentInfoWidget ();
    /// @}

  private:
    yap::WidgetDialogBox* battleInfoDialogBox_;
    PokemonBattleInfoWidget* pokemonInfoWidget_;
    OpponentBattleInfoWidget* opponentInfoWidget_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINTERFACE_HPP
