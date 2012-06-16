#ifndef YAPOG_CLIENT_OPPONENTBATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_OPPONENTBATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"

# include "Battle/BattleInfoWidget.hpp"

namespace ycl
{
  class OpponentBattleInfoWidget : public BattleInfoWidget
  {
    DISALLOW_COPY (OpponentBattleInfoWidget);

  public:
    OpponentBattleInfoWidget ();

    virtual void Init ();

  protected:
    virtual bool HandleOnEvent (const yap::GuiEvent& guiEvent);
  };
} // namespace ycl

#endif // YAPOG_CLIENT_OPPONENTBATTLEINFOWIDGET_HPP
