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

  /*
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
  */

  PokemonTeam* PokemonSelectRequest::SelectPokemonTeam (
    const yap::ID& accountID)
  {
    yap::String queryString = 
      "SELECT "
      "pokemon.pokemon_id, "
      "pokemon.pokemon_static_id, "
      "pokemon.pokemon_experience, "
      "pokemon.pokemon_gender, "
      "pokemon.pokemon_nickname, "
      "pokemon.pokemon_shiny, "
      "pokemon.pokemon_loyalty, "
      "pokemon.pokemon_nature, "
      "pokemon.pokemon_trading_number, "
      "pokemon.pokemon_trader_account_id, "
      "pokemon.pokemon_box_number, "
      "pokemon.pokemon_box_index, "
      "pokemon.pokemon_catch_date, "
      "pokemon.pokemon_status, "

      "pokemon_stats.pokemon_stats_hp, "
      "pokemon_stats.pokemon_stats_max_hp, "
      "pokemon_stats.pokemon_stats_attack, "
      "pokemon_stats.pokemon_stats_defense, "
      "pokemon_stats.pokemon_stats_special_attack, "
      "pokemon_stats.pokemon_stats_special_defense, "
      "pokemon_stats.pokemon_stats_speed "

      "FROM pokemon "
      "INNER JOIN pokemon_stats ON "
      "pokemon_stats.pokemon_id = pokemon.pokemon_id "
      "WHERE account_id = :accountID AND pokemon_box_number = 0";

    yap::DatabaseStream select (
      queryString, 
      databaseManager_.GetConnection ());

    select.Write (accountID);

    if (select.EndOfStream ())
      throw yap::DatabaseException ("This pokemon doesn't exist !");

    // Read data from database
    int counter = 0;
    PokemonTeam* pokemonTeam = new PokemonTeam ();

    while (!select.EndOfStream ())
    {
      PokemonTable* pokemonTable = new PokemonTable ();

      // Get the Pokemon's basic data
      pokemonTable->accountID_ = accountID;
      pokemonTable->id_ = select.ReadID ();
      pokemonTable->staticID_ = select.ReadID ();
      pokemonTable->experience_ = select.ReadUInt ();
      pokemonTable->gender_ = static_cast<yap::Gender>(select.ReadUInt ());
      pokemonTable->nickname_ = select.ReadString ();
      pokemonTable->shiny_ = select.ReadBool ();
      pokemonTable->loyalty_ = select.ReadInt ();
      pokemonTable->nature_ = select.ReadID ();
      pokemonTable->tradingNumber_ = select.ReadUInt ();
      pokemonTable->traderAccountID_ = select.ReadID ();
      pokemonTable->boxNumber_ = select.ReadUInt ();
      pokemonTable->boxIndex_ = select.ReadID ();
      pokemonTable->catchDate_ = select.ReadString ();
      pokemonTable->status_ = static_cast<yap::PokemonStatus>(select.ReadUInt ());

      // Get the Pokemon's stats value
      yap::HitPoint hp (select.ReadUInt16 ());
      hp.SetCurrentValue (select.ReadUInt16 ());
      yap::Attack attack (select.ReadUInt16 ());
      yap::Defense defense (select.ReadUInt16 ());
      yap::SpecialAttack specialAttack (select.ReadUInt16 ());
      yap::SpecialDefense specialDefense (select.ReadUInt16 ());
      yap::Speed speed (select.ReadUInt16 ());

      // Get the Pokemon's stats EV
      /*
      hp.SetEffortValue (select.ReadUInt16 ());
      attack.SetEffortValue (select.ReadUInt16 ());
      defense.SetEffortValue (select.ReadUInt16 ());
      specialAttack.SetEffortValue (select.ReadUInt16 ());
      specialDefense.SetEffortValue (select.ReadUInt16 ());
      speed.SetEffortValue (select.ReadUInt16 ());
      */

      yap::PokemonStat stats (
        hp,
        attack, 
        defense, 
        specialAttack, 
        specialDefense, 
        speed);

      // Get the Pokemon's moves from PokemonMoveSelectRequest
      yap::collection::Array<yap::PokemonMove*> moveSet (4, nullptr);

      pokemonTeam->AddPokemon (pokemonTable->CreatePokemon (stats, moveSet));

      counter++;

      if (counter > 6)
        throw yap::DatabaseException ("This team have more of 6 Pokemon !");
    }

    return pokemonTeam;
  }

} // namespace yse