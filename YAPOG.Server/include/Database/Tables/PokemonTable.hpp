#ifndef YAPOG_POKEMONTABLE_HPP
# define YAPOG_POKEMONTABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Tables/ITable.hpp"

namespace yap
{
  class Pokemon;
}

namespace yse
{
  class PokemonTable : public ITable
  {
    DISALLOW_COPY(PokemonTable);
  public:
    PokemonTable (const yap::ID& accountID);

    void LoadFromPokemon (const yap::Pokemon& pokemon);

    /// Getters
    const yap::ID& GetAccountID () const;
    const yap::ID& GetID () const;
    const yap::ID& GetStaticID () const;
    const yap::UInt32& GetExperience () const;
    const yap::UInt8& GetGender () const;
    const yap::String& GetNickname () const;
    const yap::UInt16& GetLevel () const;
    const bool GetShiny () const;
    const yap::Int16& GetLoyalty () const;
    const yap::ID& GetNature () const;
    const yap::UInt16& GetTradingNumber () const;
    const yap::ID& GetTraderAccountID () const;

    /// Setters
    //void SetAccountID (const yap::ID& value);
    void SetID (const yap::ID& value);
    void SetStaticID (const yap::ID& value);
    void SetExperience (const yap::UInt32& value);
    void SetGender (const yap::UInt8& value);
    void SetNickname (const yap::String& value);
    void SetLevel (const yap::UInt16& value);
    void SetShiny (const bool value);
    void SetLoyalty (const yap::Int16& value);
    void SetNature (const yap::ID& value);
    void SetTradingNumber (const yap::UInt16& value);
    void SetTraderAccountID (const yap::ID& value);

    void DisplayData ();

  private:
    yap::ID accountID_;
    yap::ID id_;
    yap::ID staticID_;
    yap::UInt32 experience_;
    yap::UInt8 gender_;
    yap::String nickname_;
    yap::UInt16 level_;
    bool shiny_;
    yap::Int16 loyalty_;
    yap::ID nature_;
    yap::UInt32 tradingNumber_;
    yap::ID traderAccountID_;

    static const yap::ID DEFAULT_ID;
    static const yap::ID DEFAULT_STATIC_ID;
    static const yap::UInt32 DEFAULT_EXPERIENCE;
    static const yap::UInt8 DEFAULT_GENDER;
    static const yap::String DEFAULT_NICKNAME;
    static const yap::UInt16 DEFAULT_LEVEL;
    static const bool DEFAULT_SHINY;
    static const yap::Int16 DEFAULT_LOYALTY;
    static const yap::ID DEFAULT_NATURE;
    static const yap::UInt32 DEFAULT_TRADING_NUMBER;
    static const yap::ID DEFAULT_TRADER_ACCOUNT_ID;
  };
} // namespace yse

#endif // YAPOG_POKEMONTABLE_HPP