#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

#include "Database/Requests/Inserts/PokemonMoveInsertRequest.hpp"
#include "Database/Tables/PokemonMoveTable.hpp"

namespace yse
{
  PokemonMoveInsertRequest::PokemonMoveInsertRequest 
    (const PokemonMoveTable& pokemonMoveTable)
    : pokemonMoveTable_ (pokemonMoveTable)
  {
  }

  PokemonMoveInsertRequest::~PokemonMoveInsertRequest ()
  {
  }

  bool PokemonMoveInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "INSERT INTO pokemon_move ("
      "pokemon_id, "
      "pokemon_move_static_id, "
      "pokemon_move_index, "
      "pokemon_move_pp, "
      "pokemon_move_max_pp"
      ")"
      "VALUES ("
      ":pokemonID, "
      ":staticID, "
      ":index, "
      ":pp, "
      ":maxPP"
      ")";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    try
    {
      query.Write (pokemonMoveTable_.pokemonID_);
      query.Write (pokemonMoveTable_.staticID_);
      query.Write (pokemonMoveTable_.index_);
      query.Write (pokemonMoveTable_.pp_);
      query.Write (pokemonMoveTable_.maxPP_);

      return true;
    }
    catch (const pgs::pg_excpt& e)
    {
      std::cerr << e.errmsg () << std::endl;
    }

    return false;
  }
} // namespace yse