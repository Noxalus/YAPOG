#ifndef YAPOG_CLIENT_BATTLEMENU_HPP
# define YAPOG_CLIENT_BATTLEMENU_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GridMenu.hpp"
# include "YAPOG/Graphics/Gui/MenuItem.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace ycl
{
  class BattleMenu : public yap::GridMenu
  {
    DISALLOW_COPY (BattleMenu);

  public:
    BattleMenu ();
    virtual ~BattleMenu ();

  private:
    yap::MenuItem fightItem_;
    yap::MenuItem bagItem_;
    yap::MenuItem pokemonItem_;
    yap::MenuItem runItem_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEMENU_HPP
