#ifndef YAPOG_POKEMONSTATSTABLE_HPP
# define YAPOG_POKEMONSTATSTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"

namespace yse
{
  class Pokemon;

  class PokemonIVTable : public ITable
  {
    DISALLOW_COPY(PokemonIVTable);
  public:
    PokemonIVTable ();

    void LoadFromPokemon (const Pokemon& pokemon);

    yap::ID pokemonID_;
    yap::UInt16 hp_;
    yap::UInt16 attack_;
    yap::UInt16 defense_;
    yap::UInt16 specialAttack_;
    yap::UInt16 specialDefense_;
    yap::UInt16 speed_;
  };
} // namespace yse

#endif // YAPOG_POKEMONSTATSTABLE_HPP