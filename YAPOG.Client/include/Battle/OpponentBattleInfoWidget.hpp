#ifndef YAPOG_CLIENT_OPPONENTBATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_OPPONENTBATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp";
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp";

# include "Battle/BaseBattleWidget.hpp"

namespace ycl
{
  class OpponentBattleInfoWidget : public BaseBattleWidget
  {
    DISALLOW_COPY (OpponentBattleInfoWidget);

  public:
    OpponentBattleInfoWidget ();

    /// @name Getters.
    /// @{
    yap::Label& GetOpponentName ();
    /// @}

  private:
    /// @name Labels.
    /// @{
    yap::Label opponentName_;
    yap::Label opponentLevel_;
    /// @}

    /// @name Layouts.
    /// @{
    yap::HorizontalLayout horizontalLayout_;
    yap::VerticalLayout verticalLayout_;
    /// @}
  };
} // namespace ycl

#endif // YAPOG_CLIENT_OPPONENTBATTLEINFOWIDGET_HPP
