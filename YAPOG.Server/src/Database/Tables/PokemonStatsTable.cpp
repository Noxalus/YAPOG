#include "Database/Tables/PokemonStatsTable.hpp"

namespace yse
{
  PokemonStatsTable::PokemonStatsTable ()
    : pokemonID_ (1)
  {
  }

  /*
  void PokemonStatsTable::LoadFromX (const X& x)
  {
  }
  */

  /// Getters
  const yap::ID& PokemonStatsTable::GetPokemonID () const
  { return pokemonID_; }

  /// Setters
  void PokemonStatsTable::SetPokemonID (const yap::ID& value) 
  { pokemonID_ = value; }

  void PokemonStatsTable::DisplayData ()
  {
    std::cout << "ID: " << pokemonID_.GetValue () << std::endl;
  }

} // namespace yse