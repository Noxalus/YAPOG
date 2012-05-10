#include "Database/Requests/Updates/AccountUpdateRequest.hpp"

namespace yse
{
  AccountUpdateRequest::AccountUpdateRequest (const AccountTable& accountTable)
    : accountTable_ (accountTable)
  {
  }

  bool AccountUpdateRequest::Update (yap::DatabaseManager& databaseManager)
  {
    /* @TODO */
    return false;
  }

} // namespace yse