#ifndef YAPOG_POKEMONSTATSTABLE_HPP
# define YAPOG_POKEMONSTATSTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"
# include "YAPOG/Game/Pokemon/PokemonStat.hpp"

namespace yse
{
  class Pokemon;

  class PokemonStatsTable : public ITable
  {
    DISALLOW_COPY(PokemonStatsTable);
  public:
    PokemonStatsTable ();

    void LoadFromPokemon (const Pokemon& pokemon);

    yap::ID pokemonID_;
    yap::PokemonStat stats_;
  };
} // namespace yse

#endif // YAPOG_POKEMONSTATSTABLE_HPP