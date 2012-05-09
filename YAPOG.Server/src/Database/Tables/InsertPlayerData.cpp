#include "Database/Tables/InsertPlayerData.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "Account/PlayerData.hpp"

InsertPlayerData::InsertPlayerData (const PlayerData& playerData)
  : playerData_ (playerData)
{
}

InsertPlayerData::~InsertPlayerData ()
{
}

bool InsertPlayerData::Add (yap::DatabaseManager& databaseManager)
{
  pg_trans tr (databaseManager.GetConnection ());

  yap::String query_string = 
    "INSERT INTO player_data "
    "(account_id, player_data_position) "
    "VALUES (:accountID, :position)";

  yap::String positionString 
    ("(" + yap::StringHelper::ToString (playerData_.GetPosition ().x) + 
    "," + yap::StringHelper::ToString (playerData_.GetPosition ().y) + ")");

  pg_stream query (query_string, databaseManager.GetConnection ());
  query << playerData_.GetAccountID ().GetValue () << positionString;

  tr.commit ();

  return true;
}