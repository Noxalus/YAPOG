#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonInsertRequest.hpp"
#include "Database/Tables/PokemonTable.hpp"

namespace yse
{
  PokemonInsertRequest::PokemonInsertRequest 
    (const PokemonTable& pokemonTable)
    : pokemonTable_ (pokemonTable)
    , id_ ()
  {
  }

  PokemonInsertRequest::~PokemonInsertRequest ()
  {
  }

  bool PokemonInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
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
      query.Write (pokemonTable_.GetAccountID ().GetValue ());
      query.Write (pokemonTable_.GetStaticID ());
      query.Write (pokemonTable_.GetExperience ());
      query.Write (pokemonTable_.GetGender ());
      query.Write (pokemonTable_.GetNickname ());
      query.Write (pokemonTable_.GetLevel ());
      query.Write (pokemonTable_.GetShiny ());
      query.Write (pokemonTable_.GetLoyalty ());
      query.Write (pokemonTable_.GetNature ());
      query.Write (pokemonTable_.GetTradingNumber ());
      query.Write (pokemonTable_.GetTraderAccountID ());
      query.Write (pokemonTable_.GetBoxNumber ());
      query.Write (pokemonTable_.GetBoxIndex ());

      id_ = yap::ID (query.ReadInt ());

      return true;
    }
    catch (const pgs::pg_excpt& e)
    {
      std::cerr << e.errmsg () << std::endl;
    }
  }

  const yap::ID& PokemonInsertRequest::GetID ()
  {
    return id_;
  }

} // namespace yse