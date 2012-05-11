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
      "SELECT player_data_position "
      "FROM player_data "
      "WHERE account_id = :accountID";

    yap::DatabaseStream select (queryString, dm.GetConnection ());

    select.Write (playerDataTable.GetAccountID ().GetValue ());

    if (select.EndOfStream ())
      throw yap::Exception ("This account doesn't have any player data !");

    yap::Vector2 position = select.ReadVector2 ();

    playerDataTable.SetPosition (position);

    if (!select.EndOfStream ())
      throw yap::Exception ("Account information loading error !");
  }
} // namespace yse