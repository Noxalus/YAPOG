#ifndef YAPOG_SERVER_POKEMON_HPP
# define YAPOG_SERVER_POKEMON_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Pokemon/Pokemon.hpp"

# include "Database/Tables/PokemonTable.hpp"

namespace yap
{
  class PokemonMoveSet;
}

namespace yse
{
  class Pokemon : public yap::Pokemon
  {
    DISALLOW_COPY (Pokemon);

  public:
    Pokemon (const yap::ID& staticID);

    Pokemon (
      const yap::ID& staticID, 
      const yap::UInt16& level, 
      const bool& shiny);
    virtual ~Pokemon ();

    Pokemon (
      const yap::ID& uniqueID,
      const yap::ID& staticID,
      const yap::String& nickname,
      const yap::PokemonStat& stats,
      const yap::Gender& gender,
      const yap::PokemonStatus& status,
      const bool shiny,
      const yap::Int16& loyalty,
      const yap::PokemonMoveSet& moveSet,
      const yap::ID& natureID,
      const yap::uint& exp,
      const yap::UInt8& boxNumber,
      const yap::ID& boxIndex,
      const yap::String& catchDate);

    friend class PokemonTable;

  };
} // namespace yse

#endif // YAPOG_SERVER_POKEMON_HPP

