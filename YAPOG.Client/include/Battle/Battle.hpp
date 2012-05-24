#ifndef YAPOG_CLIENT_BATTLE_HPP
# define YAPOG_CLIENT_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

namespace yap
{
  class ISprite;
}

namespace ycl
{
  class Battle 
    : public yap::Battle
    , public yap::IDrawable
  {
  public:
    Battle (yap::IBattleEntity& playerTeam, yap::IBattleEntity& opponent);
    virtual ~Battle ();

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

  private:
    /// Sprites
    yap::ISprite* background_;
    yap::ISprite* playerGround_;
    yap::ISprite* opponentGround_;

    static const yap::Vector2 DEFAULT_OPPONENT_GROUND_SPRITES_SCALE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WILDBATTLE_HPP
