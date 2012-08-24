#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonMoveInsertRequest.hpp"
#include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  PokemonMoveInsertRequest::PokemonMoveInsertRequest 
    (const PokemonMoveTable& pokemonMoveTable)
    : pokemonMoveTable_ (pokemonMoveTable)
    , id_ ()
  {
  }

  PokemonMoveInsertRequest::~PokemonMoveInsertRequest ()
  {
  }

  bool PokemonMoveInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
    /*
    yap::String query_string = 
      "INSERT INTO pokemon ("
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
      ")"
      "VALUES ("
      ":accountID, "
      ":staticID, " 
      ":experience, "
      ":gender, "
      ":nickname, "
      ":level, "
      ":shiny, "
      ":loyalty, "
      ":nature, "
      ":tradingNumber, "
      ":traderAccountID, "
      ":boxNumber, "
      ":boxIndex, "
      "NOW ()"
      ")"
      "RETURNING pokemon_id";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    try
    {
      query.Write (pokemonMoveTable_.GetAccountID ().GetValue ());
      query.Write (pokemonMoveTable_.GetStaticID ());
      query.Write (pokemonMoveTable_.GetExperience ());
      query.Write (pokemonMoveTable_.GetGender ());
      query.Write (pokemonMoveTable_.GetNickname ());
      query.Write (pokemonMoveTable_.GetLevel ());
      query.Write (pokemonMoveTable_.GetShiny ());
      query.Write (pokemonMoveTable_.GetLoyalty ());
      query.Write (pokemonMoveTable_.GetNature ());
      query.Write (pokemonMoveTable_.GetTradingNumber ());
      query.Write (pokemonMoveTable_.GetTraderAccountID ());
      query.Write (pokemonMoveTable_.GetBoxNumber ());
      query.Write (pokemonMoveTable_.GetBoxIndex ());

      id_ = yap::ID (query.ReadInt ());

      return true;
    }
    catch (const pgs::pg_excpt& e)
    {
      std::cerr << e.errmsg () << std::endl;
    }
    */

    return false;
  }

  const yap::ID& PokemonMoveInsertRequest::GetID ()
  {
    return id_;
  }

} // namespace yse