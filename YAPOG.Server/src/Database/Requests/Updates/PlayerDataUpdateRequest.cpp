#include "Database/Requests/Updates/PlayerDataUpdateRequest.hpp"

namespace yse
{
  PlayerDataUpdateRequest::PlayerDataUpdateRequest 
    (const PlayerDataTable& playerDataTable)
    : playerDataTable_ (playerDataTable)
  {
  }

  bool PlayerDataUpdateRequest::Update (yap::DatabaseManager& databaseManager)
  {
    /* @TODO */
    return false;
  }

} // namespace yse