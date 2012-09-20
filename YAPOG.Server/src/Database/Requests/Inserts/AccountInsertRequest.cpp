#include "Database/Requests/Inserts/AccountInsertRequest.hpp"
#include "Database/Tables/AccountTable.hpp"
#include "YAPOG/Database/DatabaseStream.hpp"

namespace yse
{
  AccountInsertRequest::AccountInsertRequest (const AccountTable& accountTable)
    : id_ ()
    , accountTable_ (accountTable)
  {
  }

  AccountInsertRequest::~AccountInsertRequest ()
  {
  }

  bool AccountInsertRequest::Insert (yap::DatabaseManager& databaseManager)
  {
    yap::String query_string =
      "INSERT INTO account ("
      "account_name, "
      "account_password, "
      "account_email, "
      "account_permissions, "
      "account_creation_date, "
      "account_last_login_date, "
      "account_creation_ip) "
      "VALUES (" 
      ":name, "
      ":pass, "
      ":email, "
      ":perm, "
      "NOW (), "
      "NOW (), "
      ":creationIp) "
      "RETURNING account_id";

    yap::DatabaseStream query 
      (query_string, databaseManager.GetConnection ());

    query.Write (accountTable_.GetName ());
    query.Write (accountTable_.GetPassword ());
    query.Write (accountTable_.GetEmail ());
    query.Write (static_cast<int> (accountTable_.GetPermissions ()));
    query.Write (accountTable_.GetCreationIP ());

    id_ = yap::ID (query.ReadInt ());

    return true;
  }

  const yap::ID& AccountInsertRequest::GetID ()
  {
    return id_;
  }
} // namespace yse