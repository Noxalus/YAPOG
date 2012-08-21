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
    /*
    yap::String query_string = 
    "UPDATE pokemon "
    "SET "
    "pokemon_position = :position, "
    "pokemon_map_id = :mapID, "
    "pokemon_time = :playTime, "
    "pokemon_step_count = :stepCount, "
    "pokemon_respawn_spot = :respawnSpot, "
    "pokemon_flee_count = :fleeCount, "
    "pokemon_box_number = :boxNumber, "
    "pokemon_battle_count = :battleCount, "
    "pokemon_money = :money "
    "WHERE account_id = :accountID";

    yap::DatabaseStream query 
    (query_string, databaseManager.GetConnection ());

    query.Write (pokemonTable_.GetPosition ());
    query.Write (pokemonTable_.GetMapID ());
    query.Write (pokemonTable_.GetPlayTime ());
    query.Write (pokemonTable_.GetStepCount ());
    query.Write (pokemonTable_.GetRespawnSpot ());
    query.Write (pokemonTable_.GetFleeCount ());
    query.Write (pokemonTable_.GetBoxNumber ());
    query.Write (pokemonTable_.GetBattleCount ());
    query.Write (pokemonTable_.GetMoney ());
    query.Write (pokemonTable_.GetAccountID ());
    */
    return true;
  }

} // namespace yse