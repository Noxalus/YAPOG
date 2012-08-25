#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonIVInsertRequest.hpp"
#include "Database/Tables/PokemonIVTable.hpp"

namespace yse
{
  PokemonIVInsertRequest::PokemonIVInsertRequest 
    (const PokemonIVTable& pokemonStatsTable)
    : pokemonIVTable_ (pokemonStatsTable)
  {
  }

  PokemonIVInsertRequest::~PokemonIVInsertRequest ()
  {
  }

  bool PokemonIVInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "INSERT INTO pokemon_iv ("
      "pokemon_id, "
      "pokemon_iv_hp, "
      "pokemon_iv_attack, "
      "pokemon_iv_defense, "
      "pokemon_iv_special_attack, "
      "pokemon_iv_special_defense, "
      "pokemon_iv_speed"
      ")"
      "VALUES ("
      ":pokemonID, "
      ":hp, "
      ":attack, "
      ":defense, "
      ":specialAttack, "
      ":specialDefense, "
      ":speed"
      ")";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    try
    {
      query.Write (pokemonIVTable_.pokemonID_);
      query.Write (pokemonIVTable_.hp_);
      query.Write (pokemonIVTable_.attack_);
      query.Write (pokemonIVTable_.defense_);
      query.Write (pokemonIVTable_.specialAttack_);
      query.Write (pokemonIVTable_.specialDefense_);
      query.Write (pokemonIVTable_.speed_);

      return true;
    }
    catch (const pgs::pg_excpt& e)
    {
      std::cerr << e.errmsg () << std::endl;
    }

    return false;
  }

} // namespace yse