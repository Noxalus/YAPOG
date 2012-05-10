#ifndef YAPOG_PLAYERDATAUPDATEREQUEST_HPP
# define YAPOG_PLAYERDATAUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/PlayerDataTable.hpp"

namespace yse
{
  class PlayerDataUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(PlayerDataUpdateRequest);
  public:
    PlayerDataUpdateRequest (const PlayerDataTable& playerDataTable);

    /// @name ISpatial members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}
  private:
    const PlayerDataTable& playerDataTable_;
  };
} // namespace yse

#endif // YAPOG_PLAYERDATAUPDATEREQUEST_HPP