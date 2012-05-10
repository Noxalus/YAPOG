#include "Database/Requests/Inserts/AccountInsertRequest.hpp"
#include "Database/Tables/AccountTable.hpp"

namespace yse
{
  AccountInsertRequest::AccountInsertRequest (const AccountTable& accountTable)
    : accountTable_ (accountTable)
  {
  }

  AccountInsertRequest::~AccountInsertRequest ()
  {
  }

  bool AccountInsertRequest::Insert (yap::DatabaseManager& databaseManager)
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
      << accountTable_.GetName ()
      << accountTable_.GetPassword () 
      << accountTable_.GetEmail () 
      << static_cast<int> (accountTable_.GetPermissions ())
      << "NOW()" 
      << "NOW()" 
      << accountTable_.GetCreationIP ();

    int id;
    query >> id;
    id_ = yap::ID (id);

    tr.commit ();

    return true;
  }

  const yap::ID& AccountInsertRequest::GetID ()
  {
    return id_;
  }
} // namespace yse