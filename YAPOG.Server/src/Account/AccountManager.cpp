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

void AccountManager::Login (const yap::String& name, const yap::String& password, const yap::String& current_ip)
{
	std::cout << "Login of \"" << name << "\" (pass: \"" << password << "\") !" << std::endl;

	SelectAccount* sa = new SelectAccount (databaseManager_, name);
	accounts_.Add (name, sa);

	yap::String encodedPassword = EncodePassword (password);

	// Check if this is the corresponding password
	if (sa->GetPassword () != encodedPassword)
		throw yap::Exception ("Wrong password !");

	// Check if the account is already logged in
	if (sa->IsLogged ())
		throw yap::Exception ("A person is already using this account !");

	// Record the login IP
	sa->SetCurrentIp (current_ip);
	yap::String queryString = "UPDATE account SET account_current_ip = :currentIp WHERE account_name = :name";
	pg_stream queryUpdateCurrentIp (queryString, databaseManager_.GetConnection ());
	queryUpdateCurrentIp << current_ip << name;
	std::cout << "This account is now in use for the server and the database !" << std::endl;

	if (sa->IsLogged ())
		std::cout << "This account is logged !" << std::endl;
}

void AccountManager::DisplayAllAccounts ()
{
	yap::String current_account;

	try
	{
		pg_stream accounts ("SELECT account_name FROM account", databaseManager_.GetConnection ());

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

yap::String AccountManager::EncodePassword (const yap::String& password)
{
	yap::String encodedPassword = password;
	int counter = password.length ();

	while (counter < 32)
	{
		encodedPassword += ' ';
		counter++;
	}

	return encodedPassword;
}

void AccountManager::Disconnect (const yap::String& name)
{
	if (!accounts_.Contains (name))
		throw yap::Exception ("This account doesn't log in !");

	accounts_.Remove (name);
	std::cout << name << " is now disconnected !" << std::endl;
}