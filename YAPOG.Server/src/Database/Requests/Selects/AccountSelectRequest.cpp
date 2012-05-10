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

    pg_stream select (queryString, dm.GetConnection ());
    select << name;

    if (select.eof ())
      throw yap::Exception ("This account doesn't exist !");

    // Get information from database
    int id;
    int permissions;
    yap::String password;
    yap::String email;
    yap::String creationDate;
    yap::String creationIP;
    yap::String currentIP;

    select >> id;
    select >> password;
    select >> email;
    select >> permissions;
    select >> creationDate;
    select >> creationIP;
    select >> currentIP;

    // Set the value of this account with the database information
    accountTable.SetID (yap::ID (id));
    accountTable.SetName (name);
    accountTable.SetPassword (password);
    accountTable.SetPermissions (static_cast<AccountPermission> (permissions));
    accountTable.SetCreationDate (creationDate);
    accountTable.SetCreationIP (creationIP);
    accountTable.SetCurrentIP (currentIP);

    if (!select.eof ())
      throw yap::Exception ("Account information loading error !");
  }
} // namespace yse