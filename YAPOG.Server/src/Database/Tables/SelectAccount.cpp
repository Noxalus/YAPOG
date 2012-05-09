#include "Database/Tables/SelectAccount.hpp"
#include "Account/AccountPermission.hpp"

SelectAccount::SelectAccount (
  yap::DatabaseManager& dm, 
  const yap::String& name,
  Account& account)
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
  account.SetID (yap::ID (id));
  account.SetName (name);
  account.SetPassword (password);
  account.SetPermissions (static_cast<AccountPermission> (permissions));
  account.SetCreationDate (creationDate);
  account.SetCreationIP (creationIP);
  account.SetCurrentIP (currentIP);

  if (!select.eof ())
    throw yap::Exception ("Account information loading error !");
}