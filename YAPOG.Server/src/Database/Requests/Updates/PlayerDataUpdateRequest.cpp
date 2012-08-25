#include "YAPOG/Database/DatabaseStream.hpp"
#include "Database/Requests/Updates/PlayerDataUpdateRequest.hpp"

namespace yse
{
  PlayerDataUpdateRequest::PlayerDataUpdateRequest 
    (const PlayerDataTable& playerDataTable)
    : playerDataTable_ (playerDataTable)
  {
  }

  bool PlayerDataUpdateRequest::Update 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "UPDATE player_data "
      "SET "
      "player_data_position = :position, "
      "player_data_map_id = :mapID, "
      "player_data_time = :playTime, "
      "player_data_step_count = :stepCount, "
      "player_data_respawn_spot = :respawnSpot, "
      "player_data_flee_count = :fleeCount, "
      "player_data_box_number = :boxNumber, "
      "player_data_battle_count = :battleCount, "
      "player_data_money = :money "
      "WHERE account_id = :accountID";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (playerDataTable_.GetPosition ());
    query.Write (playerDataTable_.GetMapID ());
    query.Write (playerDataTable_.GetPlayTime ());
    query.Write (playerDataTable_.GetStepCount ());
    query.Write (playerDataTable_.GetRespawnSpot ());
    query.Write (playerDataTable_.GetFleeCount ());
    query.Write (playerDataTable_.GetBoxNumber ());
    query.Write (playerDataTable_.GetBattleCount ());
    query.Write (playerDataTable_.GetMoney ());
    query.Write (playerDataTable_.GetAccountID ());

    return true;
  }

} // namespace yse