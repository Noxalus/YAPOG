#include "YAPOG/Database/DatabaseStream.hpp"
#include "Database/Requests/Selects/AccountSelectRequest.hpp"

namespace yse
{
  AccountSelectRequest::AccountSelectRequest (
    yap::DatabaseManager& dm, 
    const yap::String& name,
    AccountTable& accountTable)
  {
    yap::String queryString = 
      "SELECT account_id, "
      "account_password, "
      "account_email, "
      "account_permissions, "
      "account_creation_date, "
      "account_creation_ip, "
      "account_current_ip "
      "FROM account "
      "WHERE account_name = :name";

    yap::DatabaseStream select (queryString, dm.GetConnection ());
    select.Write (name);

    if (select.EndOfStream ())
      throw yap::Exception ("This account doesn't exist !");

    // Set the value of this account with the database information
    accountTable.SetID (yap::ID (select.ReadInt ()));
    accountTable.SetName (name);
    accountTable.SetPassword (select.ReadString ());
    accountTable.SetEmail (select.ReadString ());
    accountTable.SetPermissions 
      (static_cast<AccountPermission> (select.ReadInt ()));
    accountTable.SetCreationDate (select.ReadString ());
    accountTable.SetCreationIP (select.ReadString ());
    accountTable.SetCurrentIP (select.ReadString ());

    if (!select.EndOfStream ())
      throw yap::Exception ("Account information loading error !");
  }
} // namespace yse