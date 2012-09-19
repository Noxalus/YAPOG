#ifndef YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"

# include "Battle/BattleInfoWidget.hpp"

namespace yap
{
  struct ISprite; 

  class HitPoint;
} // namespace yap

namespace ycl
{
  class PokemonBattleInfoWidget : public BattleInfoWidget
  {
    DISALLOW_COPY (PokemonBattleInfoWidget);

  public:
    PokemonBattleInfoWidget ();

    virtual void Init ();

    virtual void UpdateHPBar ();

    /// @name Setters.
    /// @{
    virtual void SetHitPoint (const yap::HitPoint& hp);
    /// @}

  private:
    const yap::HitPoint* hp_;
    yap::Label hpValue_;
    yap::ISprite* experienceBar_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
