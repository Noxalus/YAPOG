#include "YAPOG/Database/DatabaseStream.hpp"
#include "Database/Requests/Updates/PokemonUpdateRequest.hpp"

namespace yse
{
  PokemonUpdateRequest::PokemonUpdateRequest 
    (const PokemonTable& pokemonTable)
    : pokemonTable_ (pokemonTable)
  {
  }

  bool PokemonUpdateRequest::Update 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "UPDATE pokemon "
      "SET "
      "account_id = :accountID, "
      "pokemon_static_id = :staticID, "
      "pokemon_experience = :experience, "
      "pokemon_gender = :gender, "
      "pokemon_nickname = :nickname, "
      "pokemon_shiny = :shiny,  "
      "pokemon_loyalty = :loyalty, "
      "pokemon_nature = :nature, "
      "pokemon_trading_number = :tradingNumber, "
      "pokemon_trader_account_id = :traderAccountID, "
      "pokemon_box_number = :boxNumber, "
      "pokemon_box_index = :boxInder, "
      "pokemon_box_catch_date = :catchDate "
      "WHERE pokemon_id = :pokemonID";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (pokemonTable_.accountID_.GetValue ());
    query.Write (pokemonTable_.staticID_);
    query.Write (pokemonTable_.experience_);
    query.Write (static_cast<yap::UInt8>(pokemonTable_.gender_));
    query.Write (pokemonTable_.nickname_);
    query.Write (pokemonTable_.shiny_);
    query.Write (pokemonTable_.loyalty_);
    query.Write (pokemonTable_.nature_);
    query.Write (pokemonTable_.tradingNumber_);
    query.Write (pokemonTable_.traderAccountID_);
    query.Write (pokemonTable_.boxNumber_);
    query.Write (pokemonTable_.boxIndex_);
    query.Write (pokemonTable_.catchDate_);
    
    if (query.AffectedRows () == 1)
      return true;
    else
      throw yap::DatabaseException (
      "An error occurs during the update of a Pokemon's tuple."
      "Any or too much tuple(s) seem(s) to be concerned by this update !");
  }

} // namespace yse