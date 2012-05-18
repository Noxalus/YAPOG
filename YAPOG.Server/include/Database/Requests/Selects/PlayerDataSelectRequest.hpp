#ifndef YAPOG_SELECTPLAYERDATA_HPP
# define YAPOG_SELECTPLAYERDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/PlayerDataTable.hpp"

namespace yse
{
  class PlayerDataSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(PlayerDataSelectRequest);

  public:
    PlayerDataSelectRequest (
      yap::DatabaseManager& dm, 
      PlayerDataTable& playerDataTable);
  };
} // namespace yse

#endif // YAPOG_SELECTACCOUNT_HPP