#include "Database/Tables/InsertAccount.hpp"
#include "Account/Account.hpp"

InsertAccount::InsertAccount (const Account& account)
  : account_ (account)
{
}

InsertAccount::~InsertAccount ()
{
}

bool InsertAccount::Add (yap::DatabaseManager& databaseManager)
{
  pg_trans tr (databaseManager.GetConnection ());

  yap::String query_string = "INSERT INTO account"
    "(account_name, "
    "account_password, "
    "account_email, "
    "account_permissions, "
    "account_creation_date, "
    "account_last_login_date, "
    "account_creation_ip) "
    "VALUES " 
    "(:name, "
    ":pass, "
    ":email, "
    ":perm, "
    ":creationDate, "
    ":lastLoginDate, "
    ":creationIp) "
    "RETURNING account_id";

  pg_stream query (query_string, databaseManager.GetConnection ());

  query 
    << account_.GetName ()
    << account_.GetPassword () 
    << account_.GetEmail () 
    << static_cast<int> (account_.GetPermissions ())
    << "NOW()" 
    << "NOW()" 
    << account_.GetCreationIP ();

  int id;
  query >> id;
  id_ = yap::ID (id);

  tr.commit ();

  return true;
}

const yap::ID& InsertAccount::GetID ()
{
  return id_;
}