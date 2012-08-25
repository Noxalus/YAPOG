#include "Database/Tables/PokemonMoveTable.hpp"

namespace yse
{
  PokemonMoveTable::PokemonMoveTable ()
    : pokemonID_ (1)
  {
  }

  /*
  void PokemonMoveTable::LoadFromX (const X& x)
  {
  }
  */

  /// Getters
  const yap::ID& PokemonMoveTable::GetPokemonID () const
  { return pokemonID_; }

  /// Setters
  void PokemonMoveTable::SetPokemonID (const yap::ID& value) 
  { pokemonID_ = value; }

  void PokemonMoveTable::DisplayData ()
  {
    std::cout << "ID: " << pokemonID_.GetValue () << std::endl;
  }

} // namespace yse