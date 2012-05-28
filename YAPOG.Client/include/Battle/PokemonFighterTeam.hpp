#ifndef YAPOG_CLIENT_POKEMONFIGHTERTEAM_HPP
# define YAPOG_CLIENT_POKEMONFIGHTERTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"

# include "Battle/IDrawableBattleEntity.hpp"

namespace ycl
{
  class Pokemon;
  class PokemonFighter;

  class PokemonFighterTeam
    : public yap::PokemonFighterTeam
    , public virtual IDrawableBattleEntity
  {
    DISALLOW_COPY (PokemonFighterTeam);
  public:
    PokemonFighterTeam ();
    virtual ~PokemonFighterTeam ();

    virtual PokemonFighter* GetPokemon (int index) const;
    virtual bool AddPokemon (PokemonFighter* pokemon);

    virtual yap::ISprite& GetFrontSprite ();
    virtual yap::ISprite& GetBackSprite ();

  private:
    PokemonFighter* GetCurrentFighter () const;
    yap::collection::Array<PokemonFighter*> fighters_;
  };
} // namespace ycl

#endif // YAPOG_CLIENT_POKEMONFIGHTERTEAM_HPP
