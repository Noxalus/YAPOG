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

  class BattleInterface : public BaseBattleWidget
  {
  public:
    BattleInterface ();

    /// @name Getters.
    /// @{
    yap::WidgetDialogBox& GetBattleInfoDialogBox ();
    yap::Label& GetPokemonName ();
    yap::Label& GetOpponentName ();
    /// @}

  private:
    yap::WidgetDialogBox* battleInfoDialogBox_;
    // Labels
    yap::Label pokemonName_;
    yap::Label opponentName_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINTERFACE_HPP
