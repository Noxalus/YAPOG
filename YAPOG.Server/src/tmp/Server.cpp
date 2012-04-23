#include <iostream>
#include "Database/Tables/InsertAccount.hpp"
#include "Account/AccountManager.hpp"
#include "tmp/Server.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"
#include  "YAPOG/System/String.hpp"

int main ()
{
	std::cout << "Server is starting..."
		<< std::endl;

	int selection = 0;
	yap::String username;
	yap::String password;
	yap::String email;
	yap::DatabaseManager dm;
	AccountManager am (dm);
	yap::String account;
	bool isRunning = true;

	//pg_stmt ("TRUNCATE account", dm.GetConnexion ());

	while (isRunning)
	{
		std::cout << "Please select an action:" << std::endl
			<< "1. Login" << std::endl
			<< "2. Create a new account" << std::endl
			<< "3. See all accounts" << std::endl
			<< "4. See logged accounts" << std::endl;

		std::cin >> selection;
		std::cout << std::endl;

		switch (selection)
		{
		case 1:
			std::cout << "Login !" << std::endl;
			std::cout << "Please enter a username: ";
			std::cin >> username;
			std::cout << "Password: ";
			std::cin >> password;

			am.Login (username, password, "127.0.0.1");

			std::cout << "Account information:" << std::endl;

			try
			{
				am.GetAccount (username).DisplayData ();
			}
			catch (std::exception e)
			{
				std::cerr << e.what () << std::endl;
			}

			break;
		case 2:
			std::cout << "Create new account !" << std::endl;
			std::cout << "Please enter a username: ";
			std::cin >> username;
			std::cout << "Password: ";
			std::cin >> password;
			std::cout << "Email address: ";
			std::cin >> email;

			am.CreateNewAccount (username, password, email, "127.0.0.1");

			break;
		case 3:
			std::cout << "See all accounts !" << std::endl;
			am.DisplayAllAccounts (dm);
			break;
		case 4:
			std::cout << "See logged accounts !" << std::endl;
			am.DisplayLoggedAccounts ();
			break;
		default:
			std::cout << "Invalid selection !" << std::endl;
			isRunning = false;
			break;
		}

		std::cout << std::endl;
	}

	return 0;
}
