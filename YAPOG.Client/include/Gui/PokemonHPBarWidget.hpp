#ifndef YAPOG_CLIENT_POKEMONHPBARWIDGET_HPP
# define YAPOG_CLIENT_POKEMONHPBARWIDGET_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Gui/BaseWidget.hpp"
# include "YAPOG/System/Time/UpdateableTimer.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  class PictureBox;
  class HorizontalLayout;
  class HitPoint;
}

namespace ycl
{
  class Pokemon;

  class PokemonHPBarWidget : public yap::BaseWidget
  {
    DISALLOW_COPY(PokemonHPBarWidget);

  public:
    PokemonHPBarWidget ();

    void Init ();

    void SetHitPoint (const yap::HitPoint& hp);

    void Update ();

    virtual bool IsFocusable () const;

  protected:
    virtual void HandleMove (const yap::Vector2& offset);
    virtual void HandleScale (const yap::Vector2& factor);
    virtual void HandleDraw (yap::IDrawingContext& offset);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);
    virtual void HandleUpdate (const yap::Time& dt);

  private:
    void RealUpdate ();

    const yap::HitPoint* hp_;
    yap::UInt16 previousHPValue_;
    yap::UInt16 hpValueVariance_;

    yap::PictureBox* hpBarContent_;
    yap::HorizontalLayout* mainLayout_;
    yap::UpdateableTimer hpTimer_;


    static const sf::Color DEFAULT_HP_COLOR_GOOD;
    static const sf::Color DEFAULT_HP_COLOR_MEDIUM;
    static const sf::Color DEFAULT_HP_COLOR_BAD;
    static const float MAX_HP_BAR_SIZE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONHPBARWIDGET_HPP
