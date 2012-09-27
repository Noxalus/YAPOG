#ifndef YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
# define YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/Label.hpp"
# include "YAPOG/Graphics/Gui/HorizontalLayout.hpp"
# include "YAPOG/Graphics/Gui/VerticalLayout.hpp"

# include "Battle/BattleInfoWidget.hpp"
# include "Gui/PokemonExperienceBarWidget.hpp"

namespace yap
{
  struct ISprite; 

  class HitPoint;
} // namespace yap

namespace ycl
{
  class PokemonExperience;

  class PokemonBattleInfoWidget : public BattleInfoWidget
  {
    DISALLOW_COPY (PokemonBattleInfoWidget);

  public:
    PokemonBattleInfoWidget ();

    virtual void Init ();

    virtual void UpdateHPBar ();
    void UpdateExperienceBar (yap::UInt16 levelEarned);

  protected:
    /// @name Setters.
    /// @{
    virtual void SetHitPoint (const yap::HitPoint& hp);
    virtual void SetExperience (const yap::PokemonExperience& experience);
    /// @}

  private:
    const yap::HitPoint* hp_;
    yap::Label hpValue_;
    PokemonExperienceBarWidget experienceBar_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONBATTLEINFOWIDGET_HPP
