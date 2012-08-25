#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonStatsInsertRequest.hpp"
#include "Database/Tables/PokemonStatsTable.hpp"

namespace yse
{
  PokemonStatsInsertRequest::PokemonStatsInsertRequest 
    (const PokemonStatsTable& pokemonStatsTable)
    : pokemonStatsTable_ (pokemonStatsTable)
  {
  }

  PokemonStatsInsertRequest::~PokemonStatsInsertRequest ()
  {
  }

  bool PokemonStatsInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "INSERT INTO pokemon_stats ("
      "pokemon_id, "
      "pokemon_stats_hp, "
      "pokemon_stats_max_hp, "
      "pokemon_stats_attack, "
      "pokemon_stats_defense, "
      "pokemon_stats_special_attack, "
      "pokemon_stats_special_defense, "
      "pokemon_stats_speed"
      ")"
      "VALUES ("
      ":pokemonID, "
      ":hp, "
      ":maxHP, "
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
      query.Write (pokemonStatsTable_.pokemonID_);
      query.Write (pokemonStatsTable_.stats_.GetHitPoint ().GetCurrentValue ());
      query.Write (pokemonStatsTable_.stats_.GetHitPoint ().GetValue ());
      query.Write (pokemonStatsTable_.stats_.GetAttack ().GetValue ());
      query.Write (pokemonStatsTable_.stats_.GetDefense ().GetValue ());
      query.Write (pokemonStatsTable_.stats_.GetSpecialAttack ().GetValue ());
      query.Write (pokemonStatsTable_.stats_.GetSpecialDefense ().GetValue ());
      query.Write (pokemonStatsTable_.stats_.GetSpeed ().GetValue ());

      return true;
    }
    catch (const pgs::pg_excpt& e)
    {
      std::cerr << e.errmsg () << std::endl;
    }

    return false;
  }

} // namespace yse