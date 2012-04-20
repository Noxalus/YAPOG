#include "Account/AccountManager.hpp"

AccountManager::AccountManager (yap::DatabaseManager& dm)
	: databaseManager_ (dm)
{
}

AccountManager::~AccountManager ()
{
}

void AccountManager::CreateNewAccount (const yap::String& name,
																			 const yap::String& password,
																			 const yap::String& email,
																			 const yap::String& creationIp)
{
	InsertAccount ia (name, email, password, creationIp);
	ia.Add (databaseManager_);
}

yap::ID AccountManager::Login (const yap::String& name, const yap::String& password, const yap::String& current_ip)
{
	yap::ID id (yap::ID::ValueType (-1));

	std::cout << "Login of \"" << name << "\" (pass: \"" << password << "\") !" << std::endl;

	try
	{
		pg_trans tr (databaseManager_.GetConnexion ());

		// Check if the username exists
		yap::String queryString = "SELECT * FROM account WHERE account_name = :name";
		pg_stream queryNameExists (queryString, databaseManager_.GetConnexion ());
		queryNameExists << name;

		if (queryNameExists.eof ())
		{
			std::cerr << "The username \"" << name << "\" doesn't exist !" << std::endl;
			return yap::ID (yap::ID::ValueType (-1));
		}

		std::cout << "Display account informations:" << std::endl
			<< "-----------------------" << std::endl;
		yap::String s;
		while (!queryNameExists.eof ())
		{
			queryNameExists >> s;
			std::cout << s << std::endl;
		}

		std::cout << "-----------------------" << std::endl;

		// Check if this is the corresponding password
		queryString = "UPDATE account SET account_current_ip = :currentIp WHERE account_name = :name";
		pg_stream queryUpdateCurrentIp (queryString, databaseManager_.GetConnexion ());
		queryUpdateCurrentIp << current_ip << name;

		// Check if the account is already logged in
		// TODO

		// Record the login IP
		// TODO
		/*
		yap::String query_string = "SELECT account_id FROM account WHERE account_name = :name AND account_password = :pass";
		pg_stream query (query_string, databaseManager_.GetConnexion ());
		query << name << password;

		std::cout << query.affected_rows () << std::endl;

		int int_id = 0;
		query >> int_id;
		id.SetValue (int_id);
		*/
		tr.commit ();
		/*
		if (id.GetValue () != -1)
		std::cout << "ID: " << id.GetValue () << std::endl;
		else
		std::cout << "This user doesn't exist !" << std::endl;
		*/
	}
	catch (pg_excpt e)
	{
		std::cerr << e.errmsg ();
	}

	return id;
}