#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Selects/PokemonSelectRequest.hpp"
#include "Pokemon/PokemonTeam.hpp"

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

    select.Write (pokemonTable.id_);

    if (select.EndOfStream ())
      throw yap::DatabaseException ("This pokemon doesn't exist !");

    pokemonTable.accountID_ = select.ReadID ();
    pokemonTable.staticID_ = select.ReadID ();
    pokemonTable.experience_ = select.ReadUInt ();
    pokemonTable.gender_ = (yap::Gender) select.ReadUInt ();
    pokemonTable.nickname_ = select.ReadString ();
    pokemonTable.shiny_ = select.ReadBool ();
    pokemonTable.loyalty_ = select.ReadInt ();
    pokemonTable.nature_ = select.ReadID ();
    pokemonTable.tradingNumber_ = select.ReadUInt ();
    pokemonTable.traderAccountID_ = select.ReadID ();
    pokemonTable.boxNumber_ = select.ReadUInt ();
    pokemonTable.boxIndex_ = select.ReadID ();
    pokemonTable.catchDate_ = select.ReadString ();

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

    pokemonTable->id_ = pokemonID;

    pokemonTable->accountID_ = select.ReadID ();
    pokemonTable->staticID_ = select.ReadID ();
    pokemonTable->experience_ = select.ReadUInt ();
    pokemonTable->gender_ = (yap::Gender) select.ReadUInt ();
    pokemonTable->nickname_ = select.ReadString ();
    pokemonTable->shiny_ = select.ReadBool ();
    pokemonTable->loyalty_ = select.ReadInt ();
    pokemonTable->nature_ = select.ReadID ();
    pokemonTable->tradingNumber_ = select.ReadUInt ();
    pokemonTable->traderAccountID_ = select.ReadID ();
    pokemonTable->boxNumber_ = select.ReadUInt ();
    pokemonTable->boxIndex_ = select.ReadID ();
    pokemonTable->catchDate_ = select.ReadString ();

    if (!select.EndOfStream ())
      throw yap::DatabaseException ("Pokemon information loading error !");

    return pokemonTable;
  }

  PokemonTeam* PokemonSelectRequest::SelectPokemonTeam (
    const yap::ID& accountID)
  {
    yap::collection::List<PokemonTable*>  pokemonTableTeam;

    yap::String queryString = 
      "SELECT "
      "pokemon_id, "
      "pokemon_static_id, "
      "pokemon_experience, "
      "pokemon_gender, "
      "pokemon_nickname, "
      "pokemon_shiny, "
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

      pokemonTable->accountID_ = accountID;
      pokemonTable->id_ = select.ReadID ();
      pokemonTable->staticID_ = select.ReadID ();
      pokemonTable->experience_ = select.ReadUInt ();
      pokemonTable->gender_ = (yap::Gender) select.ReadUInt ();
      pokemonTable->nickname_ = select.ReadString ();
      pokemonTable->shiny_ = select.ReadBool ();
      pokemonTable->loyalty_ = select.ReadInt ();
      pokemonTable->nature_ = select.ReadID ();
      pokemonTable->tradingNumber_ = select.ReadUInt ();
      pokemonTable->traderAccountID_ = select.ReadID ();
      pokemonTable->boxNumber_ = select.ReadUInt ();
      pokemonTable->boxIndex_ = select.ReadID ();
      pokemonTable->catchDate_ = select.ReadString ();

      pokemonTableTeam.Add (pokemonTable);

      counter++;

      if (counter > 6)
        throw yap::DatabaseException ("This team have more of 6 Pokemon !");
    }

    PokemonTeam* pokemonTeam = new PokemonTeam ();

    // Get the Pokemon's moves from PokemonMoveSelectRequest
    yap::collection::Array<yap::PokemonMove*> moveSet (4, nullptr);
    // Get the Pokemon's stats from PokemonStatsSelectRequest
    yap::PokemonStat stats;

    for (PokemonTable* pt : pokemonTableTeam)
      pokemonTeam->AddPokemon (pt->CreatePokemon (stats, moveSet));

    return pokemonTeam;
  }

} // namespace yse