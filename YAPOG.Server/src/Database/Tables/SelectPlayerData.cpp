#include "Database/Tables/SelectPlayerData.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/Collection/Array.hpp"
#include "Account/PlayerData.hpp"

SelectPlayerData::SelectPlayerData (
  yap::DatabaseManager& dm, 
  PlayerData& playerData)
{
  yap::String queryString = 
    "SELECT player_data_position "
    "FROM player_data "
    "WHERE account_id = :accountID";

  pg_stream select (queryString, dm.GetConnection ());

  select << playerData.GetAccountID ().GetValue ();

  if (select.eof ())
    throw yap::Exception ("This account doesn't have any player data !");

  yap::String positionString;
  select >> positionString;

  yap::collection::Array<yap::String> result;
  yap::StringHelper::Split (positionString, "(,)", result); 

  yap::Vector2 position = yap::Vector2 (
    yap::StringHelper::Parse<float> (result[1]), 
    yap::StringHelper::Parse<float> (result[2]));

  playerData.SetPosition (position);
  

  if (!select.eof ())
    throw yap::Exception ("Account information loading error !");
}