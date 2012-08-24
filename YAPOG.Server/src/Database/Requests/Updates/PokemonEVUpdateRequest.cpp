#include "YAPOG/Database/DatabaseStream.hpp"
#include "Database/Requests/Updates/PokemonEVUpdateRequest.hpp"

namespace yse
{
  PokemonEVUpdateRequest::PokemonEVUpdateRequest 
    (const PokemonEVTable& pokemonTable)
    : pokemonTable_ (pokemonTable)
  {
  }

  bool PokemonEVUpdateRequest::Update 
    (yap::DatabaseManager& databaseManager)
  {
    /*
    yap::String query_string = 
      "UPDATE pokemon "
      "SET "
      "account_id = :accountID, "
      "pokemon_static_id = :staticID, "
      "pokemon_experience = :experience, "
      "pokemon_gender = :gender, "
      "pokemon_nickname = :nickname, "
      "pokemon_level = :level, "
      "pokemon_shiny = :shiny,  "
      "pokemon_loyalty = :loyalty, "
      "pokemon_nature = :nature, "
      "pokemon_trading_number = :tradingNumber, "
      "pokemon_trader_account_id = :traderAccountID "
      "WHERE pokemon_id = :pokemonID";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (pokemonTable_.GetAccountID ());
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
    query.Write (pokemonTable_.GetID ());

    if (query.AffectedRows () == 1)
      return true;
    else
      throw yap::DatabaseException (
      "An error occurs during the update of a Pokemon's tuple."
      "Any tuple seems to be concerned by this update !");
    */

    return false;
  }

} // namespace yse