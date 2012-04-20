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

	try
	{
		yap::DatabaseManager dm;
		AccountManager am (dm);

		yap::String name = "COUCOU2";
		yap::String password = "Password";

		pg_stream s ("TRUNCATE account", dm.GetConnexion ());
		am.CreateNewAccount (name, password, "Email", "2001:0db8:0000:85a3:0000:0000:ac1f:8001");
		am.GetAccountId (name, password);
		/*
		
		pg_trans tr (dM.GetConnexion ());
		AccountTable at ("COUCOU #", "Email", "Password", 0, "2001:0db8:0000:85a3:0000:0000:ac1f:8001");
		for(int i = 0; i < 10000; i++)
		{
			std::string test_string ("Name #");

			if (i != 500 && i != 5)
			{
				std::ostringstream oss;
				oss << i;
				test_string += oss.str();
			}

			at.SetName (test_string);
			at.Add (dM);
		}

		tr.commit ();
		*/
		getchar();
	}
	catch (std::exception e)
	{
		std::cerr << e.what ();
		getchar();
	}

	return 0;
}
