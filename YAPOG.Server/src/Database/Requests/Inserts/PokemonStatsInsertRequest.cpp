#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonStatsInsertRequest.hpp"
#include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  PokemonStatsInsertRequest::PokemonStatsInsertRequest 
    (const PokemonStatsTable& pokemonStatsTable)
    : pokemonStatsTable_ (pokemonStatsTable)
    , id_ ()
  {
  }

  PokemonStatsInsertRequest::~PokemonStatsInsertRequest ()
  {
  }

  bool PokemonStatsInsertRequest::Insert 
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
      query.Write (pokemonStatsTable_.GetAccountID ().GetValue ());
      query.Write (pokemonStatsTable_.GetStaticID ());
      query.Write (pokemonStatsTable_.GetExperience ());
      query.Write (pokemonStatsTable_.GetGender ());
      query.Write (pokemonStatsTable_.GetNickname ());
      query.Write (pokemonStatsTable_.GetLevel ());
      query.Write (pokemonStatsTable_.GetShiny ());
      query.Write (pokemonStatsTable_.GetLoyalty ());
      query.Write (pokemonStatsTable_.GetNature ());
      query.Write (pokemonStatsTable_.GetTradingNumber ());
      query.Write (pokemonStatsTable_.GetTraderAccountID ());
      query.Write (pokemonStatsTable_.GetBoxNumber ());
      query.Write (pokemonStatsTable_.GetBoxIndex ());

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

  const yap::ID& PokemonStatsInsertRequest::GetID ()
  {
    return id_;
  }

} // namespace yse