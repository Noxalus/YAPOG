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
      "pokemon.pokemon_hp, "
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

      "pokemon_ev.pokemon_ev_hp, "
      "pokemon_ev.pokemon_ev_attack, "
      "pokemon_ev.pokemon_ev_defense, "
      "pokemon_ev.pokemon_ev_special_attack, "
      "pokemon_ev.pokemon_ev_special_defense, "
      "pokemon_ev.pokemon_ev_speed, "

      "pokemon_iv.pokemon_iv_hp, "
      "pokemon_iv.pokemon_iv_attack, "
      "pokemon_iv.pokemon_iv_defense, "
      "pokemon_iv.pokemon_iv_special_attack, "
      "pokemon_iv.pokemon_iv_special_defense, "
      "pokemon_iv.pokemon_iv_speed "

      "FROM pokemon "
      "INNER JOIN pokemon_ev ON "
      "pokemon_ev.pokemon_id = pokemon.pokemon_id "
      "INNER JOIN pokemon_iv ON "
      "pokemon_iv.pokemon_id = pokemon.pokemon_id "
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
      pokemonTable->hp_ = select.ReadUInt16 ();
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

      // Get the Pokemon's EV value
      yap::UInt16 hpEV = select.ReadUInt16 ();
      yap::UInt16 attackEV = select.ReadUInt16 ();
      yap::UInt16 defenseEV = select.ReadUInt16 ();
      yap::UInt16 specialAttackEV = select.ReadUInt16 ();
      yap::UInt16 specialDefenseEV = select.ReadUInt16 ();
      yap::UInt16 speedEV = select.ReadUInt16 ();

      // Get the Pokemon's IV value
      yap::UInt16 hpIV = select.ReadUInt16 ();
      yap::UInt16 attackIV = select.ReadUInt16 ();
      yap::UInt16 defenseIV = select.ReadUInt16 ();
      yap::UInt16 specialAttackIV = select.ReadUInt16 ();
      yap::UInt16 specialDefenseIV = select.ReadUInt16 ();
      yap::UInt16 speedIV = select.ReadUInt16 ();

      // Set the stats with EV and IV
      yap::HitPoint hp (pokemonTable->hp_, hpEV, hpIV);
      yap::Attack attack (attackEV, attackIV);
      yap::Defense defense (defenseEV, defenseIV);
      yap::SpecialAttack specialAttack (specialAttackEV, specialAttackIV);
      yap::SpecialDefense specialDefense (specialDefenseEV, specialDefenseIV);
      yap::Speed speed (speedEV, speedIV);

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