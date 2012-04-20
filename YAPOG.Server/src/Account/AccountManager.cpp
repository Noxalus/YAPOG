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

yap::ID AccountManager::GetAccountId (const yap::String& name, const yap::String& password)
{
	yap::ID id (yap::ID::ValueType (-1));

	std::cout << "Searching for the id of \"" << name << "\" (pass: \"" << password << "\") !" << std::endl;

	try
	{
		pg_trans tr (databaseManager_.GetConnexion ());
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
	}
	catch (pg_excpt e)
	{
		std::cerr << e.errmsg ();
	}

	return id;
}