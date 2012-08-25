#ifndef YAPOG_POKEMONEVTABLE_HPP
# define YAPOG_POKEMONEVTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"

namespace yse
{
  class PokemonEVTable : public ITable
  {
    DISALLOW_COPY(PokemonEVTable);
  public:
    PokemonEVTable ();

    //void LoadFromX (const X& x);

    /// Getters
    const yap::ID& GetPokemonID () const;

    /// Setters
    void SetPokemonID (const yap::ID& value);

    void DisplayData ();

  private:
    yap::ID pokemonID_;
  };
} // namespace yse

#endif // YAPOG_POKEMONEVTABLE_HPP