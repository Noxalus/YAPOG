#include "Database/Tables/PokemonIVTable.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  PokemonIVTable::PokemonIVTable ()
    : pokemonID_ (1)
    , hp_ (1)
    , attack_ (1)
    , defense_ (1)
    , specialAttack_ (1)
    , specialDefense_ (1)
    , speed_ (1)
  {
  }

  void PokemonIVTable::LoadFromPokemon (const Pokemon& pokemon)
  {
    pokemonID_ = pokemon.GetUniqueID ();

    const yap::PokemonStat& stats = pokemon.GetStats ();

    hp_ = stats.GetHitPoint ().GetIndividualValue ();
    attack_ = stats.GetAttack ().GetIndividualValue ();
    defense_ = stats.GetDefense ().GetIndividualValue ();
    specialAttack_ = stats.GetSpecialAttack ().GetIndividualValue ();
    specialDefense_ = stats.GetSpecialDefense ().GetIndividualValue ();
    speed_ = stats.GetSpeed ().GetIndividualValue ();
  }

} // namespace yse