#include "Database/Tables/PokemonEVTable.hpp"

namespace yse
{
  PokemonEVTable::PokemonEVTable ()
    : pokemonID_ (1)
  {
  }

  /*
  void PokemonEVTable::LoadFromX (const X& x)
  {
  }
  */

  /// Getters
  const yap::ID& PokemonEVTable::GetPokemonID () const
  { return pokemonID_; }

  /// Setters
  void PokemonEVTable::SetPokemonID (const yap::ID& value) 
  { pokemonID_ = value; }

  void PokemonEVTable::DisplayData ()
  {
    std::cout << "ID: " << pokemonID_.GetValue () << std::endl;
  }

} // namespace yse