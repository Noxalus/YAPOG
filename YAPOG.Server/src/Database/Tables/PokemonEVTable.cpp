#include "Database/Tables/PokemonEVTable.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  PokemonEVTable::PokemonEVTable ()
    : pokemonID_ (1)
    , hp_ (1)
    , attack_ (1)
    , defense_ (1)
    , specialAttack_ (1)
    , specialDefense_ (1)
    , speed_ (1)
  {
  }

  void PokemonEVTable::LoadFromPokemon (const Pokemon& pokemon)
  {
    pokemonID_ = pokemon.GetUniqueID ();

    const yap::PokemonStat& stats = pokemon.GetStats ();

    hp_ = stats.GetHitPoint ().GetEffortValue ();
    attack_ = stats.GetAttack ().GetEffortValue ();
    defense_ = stats.GetDefense ().GetEffortValue ();
    specialAttack_ = stats.GetSpecialAttack ().GetEffortValue ();
    specialDefense_ = stats.GetSpecialDefense ().GetEffortValue ();
    speed_ = stats.GetSpeed ().GetEffortValue ();
  }

} // namespace yse