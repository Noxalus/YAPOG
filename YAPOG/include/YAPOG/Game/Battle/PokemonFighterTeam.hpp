#ifndef YAPOG_POKEMONFIGHTERTEAM_HPP
# define YAPOG_POKEMONFIGHTERTEAM_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Battle/IBattleEntity.hpp"
# include "YAPOG/Game/Pokemon/PokemonTeam.hpp"
# include "YAPOG/Game/Battle/PokemonFighter.hpp"

namespace yap
{
  class YAPOG_LIB PokemonFighterTeam : public IBattleEntity
  {
  public:
    PokemonFighterTeam ();
    PokemonFighterTeam (const PokemonTeam& pokemonTeam);

    PokemonFighter* GetPokemon (int index) const;
    const collection::Array<PokemonFighter*>& GetTeam () const;
    bool AddPokemon (PokemonFighter* pokemon);

    /// Debug
    void PrintTeam ();
  private:
    collection::Array<PokemonFighter*> pokemons_;
  };
} // namespace yap

#endif // YAPOG_POKEMONFIGHTERTEAM_HPP
