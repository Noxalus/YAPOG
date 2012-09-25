#ifndef YAPOG_CLIENT_POKEMONHPBARWIDGET_HPP
# define YAPOG_CLIENT_POKEMONHPBARWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/ProgressBarWidget.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class HitPoint;
}

namespace ycl
{
  class Pokemon;

  class PokemonHPBarWidget : public yap::ProgressBarWidget
  {
    DISALLOW_COPY(PokemonHPBarWidget);

  public:
    PokemonHPBarWidget ();

    virtual void Init ();

    void SetHitPoint (const yap::HitPoint& hp);

    virtual void UpdateProgressBar ();

    virtual bool IsFocusable () const;
    
    virtual void RefreshWidget ();

  protected:
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    const yap::HitPoint* hp_;

    static const sf::Color DEFAULT_HP_COLOR_GOOD;
    static const sf::Color DEFAULT_HP_COLOR_MEDIUM;
    static const sf::Color DEFAULT_HP_COLOR_BAD;
    static const float MAX_HP_BAR_SIZE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONHPBARWIDGET_HPP
