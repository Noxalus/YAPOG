#ifndef YAPOG_ACCOUNTINSERTREQUEST_HPP
# define YAPOG_ACCOUNTINSERTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/String.hpp"
# include "Database/Requests/Inserts/IInsertRequest.hpp"

namespace yse
{
  class AccountTable;

  class AccountInsertRequest : public IInsertRequest
  {
    DISALLOW_COPY(AccountInsertRequest);
  public:
    AccountInsertRequest (const AccountTable& accountTable);
    virtual ~AccountInsertRequest();

    const yap::ID& GetID ();

    /// @name ISpatial members.
    /// @{
    virtual bool Insert (yap::DatabaseManager& databaseManager);
    /// @}
  private:
    yap::ID id_;
    const AccountTable& accountTable_;
  };
} // namespace yse

#endif // YAPOG_ACCOUNTINSERTREQUEST_HPP