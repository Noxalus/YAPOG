#ifndef YAPOG_POKEMONSTATSTABLE_HPP
# define YAPOG_POKEMONSTATSTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"

namespace yse
{
  class PokemonStatsTable : public ITable
  {
    DISALLOW_COPY(PokemonStatsTable);
  public:
    PokemonStatsTable ();

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

#endif // YAPOG_POKEMONSTATSTABLE_HPP