#ifndef YAPOG_CLIENT_BATTLEINTERFACE_HPP
# define YAPOG_CLIENT_BATTLEINTERFACE_HPP

# include "YAPOG/Macros.hpp"

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

    yap::WidgetDialogBox* GetBattleInfoDialogBox () const;
  private:
    yap::WidgetDialogBox* battleInfoDialogBox_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEINTERFACE_HPP
