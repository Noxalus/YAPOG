#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"
#include "Database/Requests/Inserts/PlayerDataInsertRequest.hpp"
#include "Database/Tables/PlayerDataTable.hpp"

namespace yse
{
  PlayerDataInsertRequest::PlayerDataInsertRequest 
    (const PlayerDataTable& playerDataTable)
    : playerDataTable_ (playerDataTable)
  {
  }

  PlayerDataInsertRequest::~PlayerDataInsertRequest ()
  {
  }

  bool PlayerDataInsertRequest::Insert 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "INSERT INTO player_data ("
      "account_id, "
      "player_data_position, "
      "player_data_map_position, "
      "player_data_time , "
      "player_data_step_count , "
      "player_data_respawn_spot , "
      "player_data_flee_count , "
      "player_data_box_number , "
      "player_data_battle_count , "
      "player_data_money)"
      "VALUES ("
      ":accountID, "
      ":position, " 
      ":mapPosition, "
      ":time, "
      ":stepCount, "
      ":respawnSpot, "
      ":fleeCount, "
      ":boxNumber, "
      ":battleCount, "
      ":money"
      ")";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (playerDataTable_.GetAccountID ().GetValue ());
    query.Write (playerDataTable_.GetPosition ());
    query.Write (playerDataTable_.GetMapPosition ());
    query.Write (playerDataTable_.GetPlayTime ());
    query.Write (playerDataTable_.GetStepCount ());
    query.Write (playerDataTable_.GetRespawnSpot ());
    query.Write (playerDataTable_.GetFleeCount ());
    query.Write (playerDataTable_.GetBoxNumber ());
    query.Write (playerDataTable_.GetBattleCount ());
    query.Write (playerDataTable_.GetMoney ());

    return true;
  }
} // namespace yse