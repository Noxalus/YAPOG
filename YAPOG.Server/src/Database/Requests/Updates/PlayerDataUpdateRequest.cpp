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
      "SET player_data_position = :position "
      "WHERE account_id = :accountID";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (playerDataTable_.GetPosition ());
    query.Write (playerDataTable_.GetAccountID ());

    return true;
  }

} // namespace yse