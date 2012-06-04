#ifndef YAPOG_CLIENT_BATTLEACTIONMENU_HPP
# define YAPOG_CLIENT_BATTLEACTIONMENU_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Menu.hpp"
# include "YAPOG/Graphics/Gui/MenuItem.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace ycl
{
  class ActionBattleMenu : public yap::Menu
  {
    DISALLOW_COPY (ActionBattleMenu);

  public:
    ActionBattleMenu ();
    virtual ~ActionBattleMenu ();

  private:
    yap::MenuItem fightItem_;
    yap::MenuItem bagItem_;
    yap::MenuItem pokemonItem_;
    yap::MenuItem runItem_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEACTIONMENU_HPP
