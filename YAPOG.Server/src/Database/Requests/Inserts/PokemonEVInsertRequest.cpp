#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonEVInsertRequest.hpp"
#include "Database/Tables/PokemonEVTable.hpp"

namespace yse
{
  PokemonEVInsertRequest::PokemonEVInsertRequest 
    (const PokemonEVTable& pokemonEVTable)
    : pokemonEVTable_ (pokemonEVTable)
  {
  }

  PokemonEVInsertRequest::~PokemonEVInsertRequest ()
  {
  }

  bool PokemonEVInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "INSERT INTO pokemon_ev ("
      "pokemon_id, "
      "pokemon_ev_hp, "
      "pokemon_ev_attack, "
      "pokemon_ev_defense, "
      "pokemon_ev_special_attack, "
      "pokemon_ev_special_defense, "
      "pokemon_ev_speed"
      ") "
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
      query.Write (pokemonEVTable_.pokemonID_);
      query.Write (pokemonEVTable_.hp_);
      query.Write (pokemonEVTable_.attack_);
      query.Write (pokemonEVTable_.defense_);
      query.Write (pokemonEVTable_.specialAttack_);
      query.Write (pokemonEVTable_.specialDefense_);
      query.Write (pokemonEVTable_.speed_);

      return true;
    }
    catch (const pgs::pg_excpt& e)
    {
      std::cerr << e.errmsg () << std::endl;
    }

    return false;
  }

} // namespace yse