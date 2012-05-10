#ifndef YAPOG_INSERTPLAYERDATA_HPP
# define YAPOG_INSERTPLAYERDATA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class PlayerDataTable;

  class PlayerDataInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(PlayerDataInsertRequest);

  public:
    PlayerDataInsertRequest (const PlayerDataTable& playerDataTable);
    virtual ~PlayerDataInsertRequest();

    const yap::ID& GetID ();

    /// @name ISpatial members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const PlayerDataTable& playerDataTable_;
  };

} // namespace yse

#endif // YAPOG_INSERTPLAYERDATA_HPP