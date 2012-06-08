#ifndef YAPOG_CLIENT_BATTLEMOVEMENU_HPP
# define YAPOG_CLIENT_BATTLEMOVEMENU_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/GridMenu.hpp"
# include "YAPOG/Graphics/Gui/MenuItem.hpp"

namespace ycl
{
  class BattleMoveMenu : public yap::GridMenu
  {
    DISALLOW_COPY (BattleMoveMenu);

  public:
    BattleMoveMenu ();
    virtual ~BattleMoveMenu ();

    /// @name Getters.
    /// @{
    yap::MenuItem& GetItem (int index);
    int GetIndex (yap::MenuItem& menuItem) const;
    /// @}

    /// @name Setters.
    /// @{
    void SetItemContent (int index, const yap::String& content);
    /// @}

  private:
    void Add (yap::MenuItem& menuItem, int index);

    yap::collection::Map<int, yap::MenuItem*> moves_;
    yap::collection::Map<yap::MenuItem*, int> indexes_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEMOVEMENU_HPP
