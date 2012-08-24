#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Selects/PokemonEVSelectRequest.hpp"

namespace yse
{
  PokemonEVSelectRequest::PokemonEVSelectRequest (yap::DatabaseManager& dm)
    : databaseManager_ (dm)
  {
  }

  bool PokemonEVSelectRequest::Select (PokemonEVTable& pokemonTable)
  {
    /*
    yap::String queryString = 
    "SELECT "
    "account_id, "
    "pokemon_static_id, "
    "pokemon_experience, "
    "pokemon_gender, "
    "pokemon_nickname, "
    "pokemon_level, "
    "pokemon_shiny,  "
    "pokemon_loyalty, "
    "pokemon_nature, "
    "pokemon_trading_number, "
    "pokemon_trader_account_id, "
    "pokemon_box_number, "
    "pokemon_box_index, "
    "pokemon_catch_date "
    "FROM pokemon "
    "WHERE pokemon_id = :pokemonID";

    yap::DatabaseStream select (
    queryString, 
    databaseManager_.GetConnection ());

    select.Write (pokemonTable.GetID ());

    if (select.EndOfStream ())
    throw yap::DatabaseException ("This pokemon doesn't exist !");

    pokemonTable.SetAccountID (select.ReadID ());
    pokemonTable.SetStaticID (select.ReadID ());
    pokemonTable.SetExperience (select.ReadUInt ());
    pokemonTable.SetGender (select.ReadUInt ());
    pokemonTable.SetNickname (select.ReadString ());
    pokemonTable.SetLevel (select.ReadUInt ());
    pokemonTable.SetShiny (select.ReadBool ());
    pokemonTable.SetLoyalty (select.ReadInt ());
    pokemonTable.SetNature (select.ReadID ());
    pokemonTable.SetTradingNumber (select.ReadUInt ());
    pokemonTable.SetTraderAccountID (select.ReadID ());
    pokemonTable.SetBoxNumber (select.ReadUInt ());
    pokemonTable.SetBoxIndex (select.ReadID ());
    pokemonTable.SetCatchDate (select.ReadString ());

    if (!select.EndOfStream ())
    throw yap::DatabaseException ("Pokemon information loading error !");
    */

    return false;
  }

} // namespace yse