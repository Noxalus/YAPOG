#ifndef YAPOG_ACCOUNTSELECTREQUEST_HPP
# define YAPOG_ACCOUNTSELECTREQUEST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"
# include "Database/Requests/Selects/ISelectRequest.hpp"
# include "Database/Tables/AccountTable.hpp"

namespace yse
{
  class AccountSelectRequest : public ISelectRequest
  {
    DISALLOW_COPY(AccountSelectRequest);

  public:
    AccountSelectRequest (
      yap::DatabaseManager& dm, 
      const yap::String& name,
      AccountTable& accountTable);

    void DisplayData ();
  };
} // namespace yse

#endif // YAPOG_ACCOUNTSELECTREQUEST_HPP