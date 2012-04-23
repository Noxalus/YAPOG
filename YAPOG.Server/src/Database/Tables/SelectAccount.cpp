#include "Database/Tables/SelectAccount.hpp"

SelectAccount::SelectAccount (yap::DatabaseManager& dm, const yap::String& name)
	: name_ (name)
{
	yap::String queryString = "SELECT account_id, account_password, "
		"account_email, account_permissions, account_creation_date, "
		"account_creation_ip, account_current_ip "
		"FROM account WHERE account_name = :name";

	pg_stream select (queryString, dm.GetConnection ());
	select << name;

	if (select.eof ())
		throw yap::Exception ("This account doesn't exist !");

	yap::UInt16 id;
	yap::Int16 ap;
	yap::String tmp;

	select >> id;
	select >> password_;
	select >> email_;
	select >> ap;
	select >> creationDate_;
	select >> creationIp_;
	select >> currentIp_;

	id_ = yap::ID (id);
	permissions_ = static_cast<AccountPermission> (ap);

	if (!select.eof ())
		throw yap::Exception ("Account information loading error !");
}

void SelectAccount::DisplayData ()
{
	std::cout << "ID: " << id_.GetValue () << std::endl
		<< "Username: " << name_ << std::endl
		<< "Password: " << password_ << std::endl
		<< "Email: " << email_ << std::endl
		<< "Permission: " << static_cast<yap::UInt16> (permissions_) << std::endl
		<< "Creation Date: " << creationDate_ << std::endl
		<< "Creation IP: " << creationIp_ << std::endl
		<< "Current IP: " << currentIp_ << std::endl;
}

bool SelectAccount::IsLogged ()
{
	return (currentIp_ != "");
}

void SelectAccount::SetCurrentIp (const yap::String& cip)
{
	currentIp_ = cip;
}