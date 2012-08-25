#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"
#include "YAPOG/Game/Pokemon/PokemonMoveSet.hpp"
#include "YAPOG/Game/Pokemon/Pokemon.hpp"

#include "Database/Requests/Selects/PokemonMoveSelectRequest.hpp"
#include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  PokemonMoveSelectRequest::PokemonMoveSelectRequest (yap::DatabaseManager& dm)
    : databaseManager_ (dm)
  {
  }

  /*
  bool PokemonMoveSelectRequest::Select (PokemonMoveTable& pokemonTable)
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

  return false;
  }
  */

  yap::PokemonMoveSet* PokemonMoveSelectRequest::SelectPokemonMoves (
    const yap::ID& pokemonID)
  {
    yap::String queryString = 
      "SELECT "
      "pokemon_move_static_id, "
      "pokemon_move_index, "
      "pokemon_move_pp, "
      "pokemon_move_max_pp "
      "FROM pokemon_move "
      "WHERE pokemon_id = :pokemonID";

    yap::DatabaseStream select (
      queryString, 
      databaseManager_.GetConnection ());

    select.Write (pokemonID);

    if (select.EndOfStream ())
      throw yap::DatabaseException ("This pokemon's moves doesn't exist !");

    yap::PokemonMoveSet* moves = new yap::PokemonMoveSet ();

    for (int i = 0; i < yap::Pokemon::MAX_POKEMON_MOVE_NUMBER; i++)
    {
      yap::ID moveID = select.ReadID ();

      if (moveID != yap::ID (0))
      {
        yap::PokemonMove* move = new yap::PokemonMove (moveID);
        yap::UInt16 index = select.ReadUInt16 ();
        move->SetPP (select.ReadUInt16 ());
        move->SetMaxPP (select.ReadUInt16 ());

        moves->AddMove (move, index);
      }
      else
      {
        select.ReadUInt16 ();
        select.ReadUInt16 ();
        select.ReadUInt16 ();
      }
    }

    if (!select.EndOfStream ())
      throw yap::DatabaseException ("Pokemon move information loading error !");

    return moves;
  }

} // namespace yse