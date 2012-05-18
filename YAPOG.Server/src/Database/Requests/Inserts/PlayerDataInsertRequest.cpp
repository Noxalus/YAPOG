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
      "INSERT INTO player_data "
      "(account_id, player_data_position) "
      "VALUES (:accountID, :position)";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (playerDataTable_.GetAccountID ().GetValue ());
    query.Write (playerDataTable_.GetPosition ());

    return true;
  }
} // namespace yse