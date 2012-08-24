#ifndef YAPOG_CLIENT_POKEMONFIGHTERTEAM_HPP
# define YAPOG_CLIENT_POKEMONFIGHTERTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"

# include "Battle/IDrawableBattleEntity.hpp"
# include "Battle/PokemonFighter.hpp"

namespace ycl
{
  class Pokemon;
  class PokemonTeam;

  class PokemonFighterTeam
    : public yap::PokemonFighterTeam
    , public IDrawableBattleEntity
  {
    DISALLOW_COPY (PokemonFighterTeam);
  public:
    PokemonFighterTeam ();
    virtual ~PokemonFighterTeam ();

    void LoadFromPokemonTeam (PokemonTeam& pokemonTeam, bool isOpponent);

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
    virtual bool AddPokemon (PokemonFighter* pokemon);
    virtual PokemonFighter& GetCurrentFighter ();
    virtual const PokemonFighter& GetCurrentFighter () const;
    yap::collection::Array<PokemonFighter*> fighters_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFIGHTERTEAM_HPP
