#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "Database/Requests/Selects/PokemonSelectRequest.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

namespace yse
{
  PokemonSelectRequest::PokemonSelectRequest (yap::DatabaseManager& dm)
    : databaseManager_ (dm)
  {
  }

  bool PokemonSelectRequest::Select (PokemonTable& pokemonTable)
  {
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
  }

  PokemonTable* PokemonSelectRequest::SelectPokemon (const yap::ID& pokemonID)
  {
    PokemonTable* pokemonTable = new PokemonTable ();

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

    select.Write (pokemonID);

    if (select.EndOfStream ())
      throw yap::DatabaseException ("This pokemon doesn't exist !");

    pokemonTable->SetAccountID (select.ReadID ());
    pokemonTable->SetStaticID (select.ReadID ());
    pokemonTable->SetExperience (select.ReadUInt ());
    pokemonTable->SetGender (select.ReadUInt ());
    pokemonTable->SetNickname (select.ReadString ());
    pokemonTable->SetLevel (select.ReadUInt ());
    pokemonTable->SetShiny (select.ReadBool ());
    pokemonTable->SetLoyalty (select.ReadInt ());
    pokemonTable->SetNature (select.ReadID ());
    pokemonTable->SetTradingNumber (select.ReadUInt ());
    pokemonTable->SetTraderAccountID (select.ReadID ());
    pokemonTable->SetBoxNumber (select.ReadUInt ());
    pokemonTable->SetBoxIndex (select.ReadID ());
    pokemonTable->SetCatchDate (select.ReadString ());

    if (!select.EndOfStream ())
      throw yap::DatabaseException ("Pokemon information loading error !");

    return pokemonTable;
  }

  yap::collection::List<PokemonTable*> 
    PokemonSelectRequest::SelectPokemonTeam (const yap::ID& accountID)
  {
    yap::collection::List<PokemonTable*>  pokemonTeam;

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
      "WHERE account_id = :accountID AND pokemon_box_number = 0";

    yap::DatabaseStream select (
      queryString, 
      databaseManager_.GetConnection ());

    select.Write (accountID);

    if (select.EndOfStream ())
      throw yap::DatabaseException ("This pokemon doesn't exist !");

    int counter = 0;
    while (!select.EndOfStream ())
    {
      PokemonTable* pokemonTable = new PokemonTable ();

      pokemonTable->SetAccountID (select.ReadID ());
      pokemonTable->SetStaticID (select.ReadID ());
      pokemonTable->SetExperience (select.ReadUInt ());
      pokemonTable->SetGender (select.ReadUInt ());
      pokemonTable->SetNickname (select.ReadString ());
      pokemonTable->SetLevel (select.ReadUInt ());
      pokemonTable->SetShiny (select.ReadBool ());
      pokemonTable->SetLoyalty (select.ReadInt ());
      pokemonTable->SetNature (select.ReadID ());
      pokemonTable->SetTradingNumber (select.ReadUInt ());
      pokemonTable->SetTraderAccountID (select.ReadID ());
      pokemonTable->SetBoxNumber (select.ReadUInt ());
      pokemonTable->SetBoxIndex (select.ReadID ());
      pokemonTable->SetCatchDate (select.ReadString ());

      pokemonTeam.Add (pokemonTable);

      counter++;

      if (counter > 6)
        throw yap::DatabaseException ("This team have more of 6 Pokemon !");
    }

    return pokemonTeam;
  }

} // namespace yse