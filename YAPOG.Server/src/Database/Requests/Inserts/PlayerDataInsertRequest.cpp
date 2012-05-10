#include "YAPOG/System/StringHelper.hpp"
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

  bool PlayerDataInsertRequest::Insert (yap::DatabaseManager& databaseManager)
  {
    pg_trans tr (databaseManager.GetConnection ());

    yap::String query_string = 
      "INSERT INTO player_data "
      "(account_id, player_data_position) "
      "VALUES (:accountID, :position)";

    yap::String positionString 
      ("(" + yap::StringHelper::ToString 
      (playerDataTable_.GetPosition ().x) + 
      "," + yap::StringHelper::ToString 
      (playerDataTable_.GetPosition ().y) + ")");

    pg_stream query (query_string, databaseManager.GetConnection ());
    query << playerDataTable_.GetAccountID ().GetValue () << positionString;

    tr.commit ();

    return true;
  }
} // namespace yse