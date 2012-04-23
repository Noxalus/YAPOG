#include "Account/AccountManager.hpp"

AccountManager::AccountManager (yap::DatabaseManager& dm)
	: databaseManager_ (dm),
	accounts_ ()
{
}

AccountManager::~AccountManager ()
{
	for (const auto& it : accounts_)
		delete it.second;
}

void AccountManager::CreateNewAccount (const yap::String& name,
																			 const yap::String& password,
																			 const yap::String& email,
																			 const yap::String& creationIp)
{
	InsertAccount ia (name, email, password, creationIp);

	if (ia.Add (databaseManager_))
		std::cout << "A new accout has been created ! (" << name << ")" << std::endl;
}

yap::ID AccountManager::Login (const yap::String& name, const yap::String& password, const yap::String& current_ip)
{
	yap::ID id (yap::ID::ValueType (-1));

	std::cout << "Login of \"" << name << "\" (pass: \"" << password << "\") !" << std::endl;

	try
	{
		SelectAccount* sa = new SelectAccount (databaseManager_, name);
		accounts_.Add (name, sa);

		// Check if this is the corresponding password

		// Check if the account is already logged in
		if (sa->IsLogged ())
			throw std::exception ("A person is already using this account !");

		// Record the login IP
		yap::String queryString = "UPDATE account SET account_current_ip = :currentIp WHERE account_name = :name";
		pg_stream queryUpdateCurrentIp (queryString, databaseManager_.GetConnexion ());
		queryUpdateCurrentIp << current_ip << name;
		sa->SetCurrentIp (current_ip);

		std::cout << "This account is now in use for the server and the database !" << std::endl;

		if (!sa->IsLogged ())
			throw std::exception ("You just can't use this account !");
	}
	catch (std::exception e)
	{
		std::cerr << e.what () << std::endl;
	}

	try
	{
		/*
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

		tr.commit ();

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

void AccountManager::DisplayAllAccounts (yap::DatabaseManager& dm)
{
	yap::String current_account;

	try
	{
		pg_stream accounts ("SELECT account_name FROM account", dm.GetConnexion ());

		while (!accounts.eof ())
		{
			accounts >> current_account;
			std::cout << current_account << std::endl;
		}

		std::cout << accounts.affected_rows () << " account(s) found !" << std::endl;
	}
	catch (pg_excpt e)
	{
		std::cerr << e.errmsg () << std::endl;
	}
}

void AccountManager::DisplayLoggedAccounts ()
{
	for (const auto& sa : accounts_)
		std::cout << sa.second->GetName () << std::endl;
}

SelectAccount& AccountManager::GetAccount (const yap::String& name)
{
	if (accounts_.Contains (name))
		return *accounts_[name];
	else
		throw std::exception ("This account doesn't exist !");
}