#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "Database/Requests/Selects/PlayerDataSelectRequest.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

namespace yse
{
  PlayerDataSelectRequest::PlayerDataSelectRequest (
    yap::DatabaseManager& dm, 
    PlayerDataTable& playerDataTable)
  {
    yap::String queryString = 
      "SELECT "
      "player_data_position, "
      "player_data_map_id, "
      "player_data_time, "
      "player_data_step_count, "
      "player_data_respawn_spot, "
      "player_data_flee_count, "
      "player_data_box_number, "
      "player_data_battle_count, "
      "player_data_money "
      "FROM player_data "
      "WHERE account_id = :accountID";

    yap::DatabaseStream select (queryString, dm.GetConnection ());

    select.Write (playerDataTable.GetAccountID ().GetValue ());

    if (select.EndOfStream ())
      throw yap::Exception ("This account doesn't have any player data !");

    playerDataTable.SetPosition (select.ReadVector2 ());
    playerDataTable.SetMapID (select.ReadID ());
    playerDataTable.SetPlayTime (select.ReadInt ());
    playerDataTable.SetStepCount (select.ReadInt ());
    playerDataTable.SetRespawnSpot (select.ReadVector2 ());
    playerDataTable.SetFleeCount (select.ReadInt ());
    playerDataTable.SetBoxNumber (select.ReadInt ());
    playerDataTable.SetBattleCount (select.ReadInt ());
    playerDataTable.SetMoney (select.ReadInt ());

    if (!select.EndOfStream ())
      throw yap::Exception ("Account information loading error !");
  }
} // namespace yse