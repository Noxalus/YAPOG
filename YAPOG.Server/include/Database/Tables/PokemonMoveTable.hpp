#ifndef YAPOG_POKEMONMOVETABLE_HPP
# define YAPOG_POKEMONMOVETABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"

namespace yse
{
  class Pokemon;

  class PokemonMoveTable : public ITable
  {
    DISALLOW_COPY(PokemonMoveTable);
  public:
    PokemonMoveTable ();

    void LoadFromPokemon (
      const Pokemon& pokemon, 
      const yap::ID& index);

    yap::ID pokemonID_;
    yap::ID staticID_;
    yap::ID index_;
    yap::UInt16 pp_;
    yap::UInt16 maxPP_;

    static const yap::ID DEFAULT_STATIC_ID;
    static const yap::UInt16 DEFAULT_PP;
    static const yap::UInt16 DEFAULT_MAX_PP;

  };
} // namespace yse

#endif // YAPOG_POKEMONMOVETABLE_HPP