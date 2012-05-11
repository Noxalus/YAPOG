#include "YAPOG/Database/DatabaseStream.hpp"
#include "Database/Requests/Updates/AccountUpdateRequest.hpp"

namespace yse
{
  AccountUpdateRequest::AccountUpdateRequest (const AccountTable& accountTable)
    : accountTable_ (accountTable)
  {
  }

  bool AccountUpdateRequest::Update (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "UPDATE account "
      "SET account_name = :accountName, "
      "account_password = :accountPassword, "
      "account_email = :accountEmail, "
      "account_permissions = :accountPermissions, "
      "account_creation_date = : accountCreationDate, "
      "account_last_login_date = :accountLastLoginDate, "
      "account_creation_ip = :accountCreationIP "
      "WHERE account_id = :accountID";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (accountTable_.GetName ());
    query.Write (accountTable_.GetPassword ());
    query.Write (accountTable_.GetEmail ());
    query.Write (static_cast<int> (accountTable_.GetPermissions ()));
    query.Write (accountTable_.GetCreationDate ());
    query.Write (accountTable_.GetLastLoginDate ());
    query.Write (accountTable_.GetCreationIP ());
    query.Write (accountTable_.GetID ().GetValue ());

    return true;
  }

  bool AccountUpdateRequest::UpdateLastLoginDate 
    (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string = 
      "UPDATE account "
      "SET account_last_login_date = :accountLastLoginDate "
      "WHERE account_id = :accountID";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (accountTable_.GetLastLoginDate ());
    query.Write (accountTable_.GetID ().GetValue ());

    return true;
  }

} // namespace yse