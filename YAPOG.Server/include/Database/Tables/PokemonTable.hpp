#ifndef YAPOG_POKEMONTABLE_HPP
# define YAPOG_POKEMONTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/Pokemon/PokemonStatus.hpp"
# include "YAPOG/Game/Pokemon/Gender.hpp"

# include "Database/Tables/ITable.hpp"

namespace yap
{
  class PokemonStat;
  class PokemonMoveSet;
}

namespace yse
{
  class Pokemon;

  class PokemonTable : public ITable
  {
    DISALLOW_COPY(PokemonTable);
  public:
    PokemonTable ();

    void LoadFromPokemon (const Pokemon& pokemon);

    Pokemon* CreatePokemon (
      const yap::String& trainerName,
      const yap::PokemonStat& stats, 
      const yap::PokemonMoveSet& moveSet);

    yap::ID accountID_;
    yap::ID id_;
    yap::ID staticID_;
    yap::uint experience_;
    yap::UInt16 hp_;
    yap::Gender gender_;
    yap::String nickname_;
    yap::PokemonStatus status_;
    bool shiny_;
    yap::Int16 loyalty_;
    yap::ID nature_;
    yap::uint tradingNumber_;
    yap::ID traderAccountID_;
    yap::UInt8 boxNumber_;
    yap::ID boxIndex_;
    yap::String catchDate_;

    static const yap::ID DEFAULT_ACCOUNT_ID;
    static const yap::ID DEFAULT_ID;
    static const yap::ID DEFAULT_STATIC_ID;
    static const yap::uint DEFAULT_EXPERIENCE;
    static const yap::UInt16 DEFAULT_HP;
    static const yap::Gender DEFAULT_GENDER;
    static const yap::String DEFAULT_NICKNAME;
    static const yap::PokemonStatus DEFAULT_STATUS;
    static const bool DEFAULT_SHINY;
    static const yap::Int16 DEFAULT_LOYALTY;
    static const yap::ID DEFAULT_NATURE;
    static const yap::uint DEFAULT_TRADING_NUMBER;
    static const yap::ID DEFAULT_TRADER_ACCOUNT_ID;
    static const yap::UInt8 DEFAULT_BOX_NUMBER;
    static const yap::ID DEFAULT_BOX_INDEX;
    static const yap::String DEFAULT_CATCH_DATE;
  };
} // namespace yse

#endif // YAPOG_POKEMONTABLE_HPP