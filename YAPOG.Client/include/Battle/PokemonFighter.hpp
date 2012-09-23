#ifndef YAPOG_CLIENT_POKEMONFIGHTER_HPP
# define YAPOG_CLIENT_POKEMONFIGHTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

# include "Battle/IDrawableBattleEntity.hpp"

namespace yap
{
  struct ISprite;
} // namespace yap

enum BattleSpriteType
{
  FRONT,
  BACK
};

namespace ycl
{
  class Pokemon;

  class PokemonFighter
    : public yap::PokemonFighter
    , public IDrawableBattleEntity
  {
    DISALLOW_COPY (PokemonFighter);

  public:
    PokemonFighter (Pokemon* originalPokemon, bool isOpponent);
    virtual ~PokemonFighter ();

    /// @name IDrawable members.
    /// @{
    virtual void Draw (yap::IDrawingContext& context);

    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

    /// @name IDrawableBattleEntity members
    /// @{
    virtual yap::ISprite& GetBattleSprite ();
    /// @}

    /// @name Setters.
    /// @{
    void SetBattleSprite (const BattleSpriteType& battleSpriteType);
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
    Pokemon* originalPokemon_;
    yap::ISprite* battleSprite_;
    bool isOpponent_;

    static const BattleSpriteType DEFAULT_BATTLE_SPRITE_TYPE;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFIGHTER_HPP