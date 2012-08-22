#ifndef YAPOG_ACCOUNTUPDATEREQUEST_HPP
# define YAPOG_ACCOUNTUPDATEREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "Database/Requests/Updates/IUpdateRequest.hpp"
# include "Database/Tables/AccountTable.hpp"

namespace yse
{
  class AccountUpdateRequest : public IUpdateRequest
  {
    DISALLOW_COPY(AccountUpdateRequest);
  public:
    AccountUpdateRequest (const AccountTable& accountTable);

    bool UpdateLastLoginDate (yap::DatabaseManager& databaseManager);

    /// @name IUpdateRequest members.
    /// @{
    virtual bool Update (yap::DatabaseManager& databaseManager);
    /// @}

  private:
    const AccountTable& accountTable_;
  };
} // namespace yse

#endif // YAPOG_ACCOUNTUPDATEREQUEST_HPP