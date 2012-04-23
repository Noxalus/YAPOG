#include "Database/Tables/SelectAccount.hpp"

SelectAccount::SelectAccount (yap::DatabaseManager& dm, const yap::String& name)
	: name_ (name)
{
	try
	{
		yap::String queryString = "SELECT account_id, account_password, "
			"account_email, account_permissions, account_creation_date, "
			"account_creation_ip, account_current_ip "
			"FROM account WHERE account_name = :name";

		pg_stream select (queryString, dm.GetConnexion ());
		select << name;

		/*
		yap::String tmp;
		while (!select.eof ())
		{
			select >> tmp;
			std::cout << "\"" << tmp << "\"" << std::endl;
		}
		*/
		if (select.eof ())
			throw std::exception ("This account doesn't exist !!!");

		select >> id_;
		select >> password_;
		select >> email_;
		select >> permissions_;
		yap::String tmp;
		select >> tmp;
		select >> creationIp_;
		select >> currentIp_;

		if (select.eof ())
			std::cout << "Account informations loaded !" << std::endl;
		else
			std::cerr << "Account information loading error !" << std::endl;
	}
	catch (pg_excpt e)
	{
		std::cerr << e.errmsg ();
	}
}

void SelectAccount::DisplayData ()
{
	std::cout << "ID: " << id_ << std::endl
		<< "Username: " << name_ << std::endl
		<< "Password: " << password_ << std::endl
		<< "Email: " << email_ << std::endl;
}

bool SelectAccount::IsLogged ()
{
	return (currentIp_ != "");
}