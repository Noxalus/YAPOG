#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "Database/Requests/Selects/PokemonSelectRequest.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

namespace yse
{
  PokemonSelectRequest::PokemonSelectRequest (
    yap::DatabaseManager& dm, 
    PokemonTable& pokemonTable)
  {
    /*
    yap::String queryString = 
    "SELECT "
    "pokemon_position, "
    "pokemon_map_id, "
    "pokemon_time, "
    "pokemon_step_count, "
    "pokemon_respawn_spot, "
    "pokemon_flee_count, "
    "pokemon_box_number, "
    "pokemon_battle_count, "
    "pokemon_money "
    "FROM pokemon "
    "WHERE account_id = :accountID";

    yap::DatabaseStream select (queryString, dm.GetConnection ());

    select.Write (pokemonTable.GetAccountID ().GetValue ());

    if (select.EndOfStream ())
    throw yap::Exception ("This account doesn't have any player data !");

    pokemonTable.SetPosition (select.ReadVector2 ());
    pokemonTable.SetMapID (select.ReadID ());
    pokemonTable.SetPlayTime (select.ReadInt ());
    pokemonTable.SetStepCount (select.ReadInt ());
    pokemonTable.SetRespawnSpot (select.ReadVector2 ());
    pokemonTable.SetFleeCount (select.ReadInt ());
    pokemonTable.SetBoxNumber (select.ReadInt ());
    pokemonTable.SetBattleCount (select.ReadInt ());
    pokemonTable.SetMoney (select.ReadInt ());

    if (!select.EndOfStream ())
    throw yap::Exception ("Account information loading error !");
    */
  }
} // namespace yse