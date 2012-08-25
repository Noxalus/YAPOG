#include "Database/Tables/PokemonTable.hpp"
#include "Pokemon/Pokemon.hpp"

namespace yse
{
  const yap::ID PokemonTable::DEFAULT_ACCOUNT_ID (1);
  const yap::ID PokemonTable::DEFAULT_ID (1);
  const yap::ID PokemonTable::DEFAULT_STATIC_ID (1);
  const yap::uint PokemonTable::DEFAULT_EXPERIENCE = 0;
  const yap::Gender PokemonTable::DEFAULT_GENDER = yap::Gender::Genderless;
  const yap::String PokemonTable::DEFAULT_NICKNAME ("");
  const yap::PokemonStatus PokemonTable::DEFAULT_STATUS = 
    yap::PokemonStatus::Normal;
  const bool PokemonTable::DEFAULT_SHINY = false;
  const yap::Int16 PokemonTable::DEFAULT_LOYALTY = 0;
  const yap::ID PokemonTable::DEFAULT_NATURE (1);
  const yap::uint PokemonTable::DEFAULT_TRADING_NUMBER = 0;
  const yap::ID PokemonTable::DEFAULT_TRADER_ACCOUNT_ID (1);
  const yap::UInt8 PokemonTable::DEFAULT_BOX_NUMBER = 0;
  const yap::ID PokemonTable::DEFAULT_BOX_INDEX (1);
  const yap::String PokemonTable::DEFAULT_CATCH_DATE ("");

  PokemonTable::PokemonTable ()
    : accountID_ (DEFAULT_ACCOUNT_ID) 
    , id_ (DEFAULT_ID)
    , staticID_ (DEFAULT_STATIC_ID)
    , experience_ (DEFAULT_EXPERIENCE)
    , gender_ (DEFAULT_GENDER)
    , nickname_ (DEFAULT_NICKNAME)
    , status_ (DEFAULT_STATUS)
    , shiny_ (DEFAULT_SHINY)
    , loyalty_ (DEFAULT_LOYALTY)
    , nature_ (DEFAULT_NATURE)
    , tradingNumber_ (DEFAULT_TRADING_NUMBER)
    , traderAccountID_ (DEFAULT_TRADER_ACCOUNT_ID)
    , boxNumber_ (DEFAULT_BOX_NUMBER)
    , boxIndex_ (DEFAULT_BOX_INDEX)
    , catchDate_ (DEFAULT_CATCH_DATE)
  {
  }

  void PokemonTable::LoadFromPokemon (const Pokemon& pokemon)
  {
    id_ = pokemon.uniqueID_;
    staticID_ = pokemon.staticID_;
    experience_ = pokemon.exp_->GetValue ();
    gender_ = pokemon.gender_;
    nickname_ = pokemon.nickname_;
    status_ = pokemon.status_;
    shiny_ = pokemon.shiny_;
    loyalty_ = pokemon.loyalty_;
    nature_ = pokemon.nature_->GetID ();
    tradingNumber_ = DEFAULT_TRADING_NUMBER;
    traderAccountID_ = DEFAULT_TRADER_ACCOUNT_ID;
    boxNumber_ = pokemon.boxNumber_;
    boxIndex_ = pokemon.boxIndex_;
    catchDate_ = pokemon.catchDate_;
  }

  Pokemon* PokemonTable::CreatePokemon (
    yap::PokemonStat stats, 
    yap::collection::Array<yap::PokemonMove*> moveSet)
  {
    Pokemon* pokemon = new Pokemon (
      id_, 
      staticID_,
      nickname_,
      stats,
      gender_,
      status_,
      shiny_,
      loyalty_,
      moveSet,
      nature_,
      experience_,
      boxNumber_,
      boxIndex_,
      catchDate_);

    return pokemon;
  }

} // namespace yse