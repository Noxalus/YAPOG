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

    /// @name Getters.
    /// @{
    yap::MenuItem& GetItem (int index);
    /// @}

  private:
    yap::collection::Array<yap::MenuItem*> items_;
    
    static const int ITEM_NUMBER = 4;
    static const yap::String DEFAULT_LABELS[ITEM_NUMBER];
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEMENU_HPP
