#ifndef YAPOG_CLIENT_BATTLEMOVEINFOMENU_HPP
# define YAPOG_CLIENT_BATTLEMOVEINFOMENU_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/PictureBox.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Game/Pokemon/TypeInfo.hpp"
# include "YAPOG/Game/Pokemon/PokemonMove.hpp"

# include "Battle/BaseBattleWidget.hpp"

namespace ycl
{
  class BattleMoveInfoMenu : public BaseBattleWidget
  {
    DISALLOW_COPY (BattleMoveInfoMenu);

  public:
    BattleMoveInfoMenu ();
    virtual ~BattleMoveInfoMenu ();

    /// @name Setters.
    /// @{
    void SetPPLabel (const yap::String& value);
    void SetPP (const yap::PokemonMove& skill);
    void SetType (const yap::TypeInfo& type);
    /// @}

    void HideType ();

  private:
    yap::Label pp_;
    yap::PictureBox type_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_BATTLEMOVEINFOMENU_HPP