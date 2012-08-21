#include "Database/Tables/PokemonTable.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"

namespace yse
{
  const yap::ID PokemonTable::DEFAULT_ID (1);
  const yap::ID PokemonTable::DEFAULT_STATIC_ID (1);
  const yap::UInt32 PokemonTable::DEFAULT_EXPERIENCE = 0;
  const yap::UInt8 PokemonTable::DEFAULT_GENDER = 0;
  const yap::String PokemonTable::DEFAULT_NICKNAME ("");
  const yap::UInt16 PokemonTable::DEFAULT_LEVEL = 1;
  const bool PokemonTable::DEFAULT_SHINY = false;
  const yap::Int16 PokemonTable::DEFAULT_LOYALTY = 0;
  const yap::ID PokemonTable::DEFAULT_NATURE (1);
  const yap::UInt32 PokemonTable::DEFAULT_TRADING_NUMBER = 42;
  const yap::ID PokemonTable::DEFAULT_TRADER_ACCOUNT_ID (1);

  PokemonTable::PokemonTable (
    const yap::ID& accountID)
    : accountID_ (accountID) 
    , id_ (DEFAULT_ID)
    , staticID_ (DEFAULT_STATIC_ID)
    , experience_ (DEFAULT_EXPERIENCE)
    , gender_ (DEFAULT_GENDER)
    , nickname_ (DEFAULT_NICKNAME)
    , level_ (DEFAULT_LEVEL)
    , shiny_ (DEFAULT_SHINY)
    , loyalty_ (DEFAULT_LOYALTY)
    , nature_ (DEFAULT_NATURE)
    , tradingNumber_ (DEFAULT_TRADING_NUMBER)
    , traderAccountID_ (DEFAULT_TRADER_ACCOUNT_ID)
  {
  }

  void PokemonTable::LoadFromPokemon (const yap::Pokemon& pokemon)
  {
    SetStaticID (pokemon.GetStaticID ());
    SetExperience (pokemon.GetTotalExperience ());
    SetGender ((yap::UInt8)pokemon.GetGender ());
    SetNickname (pokemon.GetName ());
    SetLevel (pokemon.GetLevel ());
    SetShiny (pokemon.GetShiny ());
    SetLoyalty (pokemon.GetLoyalty ());
    SetNature (pokemon.GetNature ());
    // @todo Finish this trading part
    SetTradingNumber (DEFAULT_TRADING_NUMBER);
    SetTraderAccountID (DEFAULT_TRADER_ACCOUNT_ID);
  }

  /// Getters
  const yap::ID& PokemonTable::GetAccountID () const
  { return accountID_; }
  const yap::ID& PokemonTable::GetID () const
  { return id_; }
  const yap::ID& PokemonTable::GetStaticID () const
  { return staticID_; }
  const yap::UInt32& PokemonTable::GetExperience () const
  { return experience_; }
  const yap::UInt8& PokemonTable::GetGender () const
  { return gender_; }
  const yap::String& PokemonTable::GetNickname () const
  { return nickname_; }
  const yap::UInt16& PokemonTable::GetLevel () const
  { return level_; }
  const bool PokemonTable::GetShiny () const
  { return shiny_; }
  const yap::Int16& PokemonTable::GetLoyalty () const
  { return loyalty_; }
  const yap::ID& PokemonTable::GetNature () const
  { return nature_; }
  const yap::UInt16& PokemonTable::GetTradingNumber () const
  { return tradingNumber_; }
  const yap::ID& PokemonTable::GetTraderAccountID () const
  { return traderAccountID_; }

  /// Setters
  void PokemonTable::SetID (const yap::ID& value) 
  { id_ = value; }
  /*
  void PokemonTable::SetAccountID (const yap::ID& value)
  { accountID_ = value; }
  */
  void PokemonTable::SetStaticID (const yap::ID& value)
  { staticID_ = value; }
  void PokemonTable::SetExperience (const yap::UInt32& value)
  { experience_ = value; }
  void PokemonTable::SetGender (const yap::UInt8& value)
  { gender_ = value; }
  void PokemonTable::SetNickname (const yap::String& value)
  { nickname_ = value; }
  void PokemonTable::SetLevel (const yap::UInt16& value)
  { level_ = value; }
  void PokemonTable::SetShiny (const bool value)
  { shiny_ = value; }
  void PokemonTable::SetLoyalty (const yap::Int16& value)
  { loyalty_ = value; }
  void PokemonTable::SetNature (const yap::ID& value)
  { nature_ = value; }
  void PokemonTable::SetTradingNumber (const yap::UInt16& value)
  { tradingNumber_ = value; }
  void PokemonTable::SetTraderAccountID (const yap::ID& value)
  { traderAccountID_ = value; }


  void PokemonTable::DisplayData ()
  {
    std::cout << "ID: " << id_.GetValue () << std::endl;
  }

} // namespace yse