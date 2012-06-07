#ifndef YAPOG_CLIENT_BATTLEINTERFACE_HPP
# define YAPOG_CLIENT_BATTLEINTERFACE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace yap
{
  class DialogBoxWidget;
  class GridMenu;
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
    yap::DialogBoxWidget& GetBattleInfoDialogBox ();
    PokemonBattleInfoWidget& GetPokemonInfoWidget ();
    OpponentBattleInfoWidget& GetOpponentInfoWidget ();
    /// @}

  private:
    yap::DialogBoxWidget* battleInfoDialogBox_;
    PokemonBattleInfoWidget* pokemonInfoWidget_;
    OpponentBattleInfoWidget* opponentInfoWidget_;
    yap::GridMenu* battleMenu_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINTERFACE_HPP
