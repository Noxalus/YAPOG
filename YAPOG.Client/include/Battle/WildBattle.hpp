#ifndef YAPOG_CLIENT_WILDBATTLE_HPP
# define YAPOG_CLIENT_WILDBATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/WildBattle.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"
# include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

namespace ycl
{
  class WildBattle 
    : public yap::WildBattle
    , public yap::IDrawable
  {
  public:
    WildBattle (
      yap::IBattleEntity& playerTeam, 
      yap::IBattleEntity& wildPokemon);
    virtual ~WildBattle ();

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

  protected:
    virtual void HandleInit ();
    virtual void HandleUpdate (const yap::Time& dt);

    virtual void HandleDraw (yap::IDrawingContext& context);
    virtual void HandleShow (bool isVisible);
    virtual void HandleChangeColor (const sf::Color& color);

    static const bool DEFAULT_VISIBLE_STATE;
    static const sf::Color DEFAULT_COLOR;

    bool isVisible_;
    sf::Color color_;

    yap::ISprite* background_;
    yap::ISprite* opponentGround_;
    yap::ISprite* playerGround_;

    static const yap::Vector2 DEFAULT_GROUND_SPRITES_SCALE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WILDBATTLE_HPP
