#include "Database/Tables/InsertAccount.hpp"

InsertAccount::InsertAccount (const yap::String& name,
															const yap::String& email,
															const yap::String& password,
															const yap::String& creationIp)
															: name_ (name),
															email_ (email),
															password_ (password),
															permissions_ (static_cast<yap::Int16>(AccountPermission::Normal)),
															creationIp_ (creationIp)
{
}

InsertAccount::~InsertAccount ()
{
}

bool InsertAccount::Add (yap::DatabaseManager& dM) const
{
	pg_trans tr (dM.GetConnection ());
	yap::String query_string = "INSERT INTO account"
		"(account_name, account_password, account_email, account_permissions, account_creation_date,  account_last_login_date, account_creation_ip) "
		"VALUES (:name, :pass, :email, :perm, :creationDate, :lastLoginDate, :creationIp)";

	pg_stream query (query_string, dM.GetConnection ());
	query << name_ << password_ << email_ << permissions_ << "NOW()" << "NOW()" << creationIp_;
	tr.commit ();

	return true;
}