#include "Database/Tables/PokemonStatsTable.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  PokemonStatsTable::PokemonStatsTable ()
    : pokemonID_ (1)
    , stats_ ()
  {
  }

  void PokemonStatsTable::LoadFromPokemon (const Pokemon& pokemon)
  {
    pokemonID_ = pokemon.GetUniqueID ();

    stats_.LoadFromPokemonStat (pokemon.GetStats ());
  }

} // namespace yse