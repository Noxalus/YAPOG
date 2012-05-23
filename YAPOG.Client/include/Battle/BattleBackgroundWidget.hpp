#ifndef YAPOG_CLIENT_BATTLEBACKGROUNDWIDGET_HPP
# define YAPOG_CLIENT_BATTLEBACKGROUNDWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/WidgetBackground.hpp"

# include "Battle/Battle.hpp"

namespace ycl
{
  class BattleBackgroundWidget : public yap::WidgetBackground
  {
  public:
    BattleBackgroundWidget ();
    virtual ~BattleBackgroundWidget ();
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEBACKGROUNDWIDGET_HPP
