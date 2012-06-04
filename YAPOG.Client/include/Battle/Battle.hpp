#ifndef YAPOG_CLIENT_BATTLE_HPP
# define YAPOG_CLIENT_BATTLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Graphics/IDrawable.hpp"

#include "Battle/IDrawableBattleEntity.hpp"

namespace yap
{
  class ISprite;
}

namespace ycl
{
  class PokemonFighterTeam;
  class PokemonFighter;

  class Battle 
    : public yap::Battle
    , public yap::IDrawable
  {
  public:
    Battle ();
    virtual ~Battle ();

    /// @name IDrawable members.
    /// @{
    virtual bool IsVisible () const;
    virtual void Show (bool isVisible);

    virtual void ChangeColor (const sf::Color& color);
    /// @}

    /// @name Getters
    /// @{
    yap::ISprite& GetBackground () const;
    yap::ISprite& GetPlayerGround () const;
    yap::ISprite& GetOpponentGround () const;
    yap::ISprite& GetPlayerTrainerBack () const;
    const yap::Vector2& GetPlayerGroundPosition () const;
    const yap::Vector2& GetOpponentGroundPosition () const;
    const IDrawableBattleEntity& GetDrawablePlayerTeam () const;
    const IDrawableBattleEntity& GetDrawableOpponent () const;
    IDrawableBattleEntity& GetDrawablePlayerTeam ();
    IDrawableBattleEntity& GetDrawableOpponent ();
    /// @}

    /// @name Setters
    /// @{
    void SetDrawablePlayerTeam (PokemonFighterTeam* pokemonTeam);
    void SetDrawableOpponent (PokemonFighterTeam* pokemonFighterTeam);
    void SetDrawableOpponent (PokemonFighter* pokemonFighter);
    /// @}

    static const yap::Vector2 DEFAULT_OPPONENT_GROUND_SPRITES_SCALE;
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
    /// General sprites
    yap::ISprite* background_;
    yap::ISprite* playerGround_;
    yap::ISprite* opponentGround_;
    yap::ISprite* playerTrainerBack_;

    /// Sprite positions
    yap::Vector2 playerGroundPosition_;
    yap::Vector2 opponentGroundPosition_;

    IDrawableBattleEntity* playerTeam_;
    IDrawableBattleEntity* opponent_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_WILDBATTLE_HPP
