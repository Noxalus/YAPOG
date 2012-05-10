#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "Database/Requests/Selects/PlayerDataSelectRequest.hpp"

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

    pg_stream select (queryString, dm.GetConnection ());

    select << playerDataTable.GetAccountID ().GetValue ();

    if (select.eof ())
      throw yap::Exception ("This account doesn't have any player data !");

    yap::String positionString;
    select >> positionString;

    yap::collection::Array<yap::String> result;
    yap::StringHelper::Split (positionString, "(,)", result); 

    yap::Vector2 position = yap::Vector2 (
      yap::StringHelper::Parse<float> (result[1]), 
      yap::StringHelper::Parse<float> (result[2]));

    playerDataTable.SetPosition (position);


    if (!select.eof ())
      throw yap::Exception ("Account information loading error !");
  }
} // namespace yse