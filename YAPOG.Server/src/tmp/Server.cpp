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

		yap::String name = "COUCOU4";
		yap::String password = "Password";

		pg_stream s ("TRUNCATE account", dm.GetConnexion ());

		pg_trans tr (dm.GetConnexion ());
		for(int i = 0; i < 100; i++)
		{
			std::string test_string ("Name #");

			if (true)
			{
				std::ostringstream oss;
				oss << i;
				test_string += oss.str();
			}

			am.CreateNewAccount (test_string, password, "Email", "2001:0db8:0000:85a3:0000:0000:ac1f:8001");
		}

		am.Login ("Name #42", password, "2001:0db8:0000:85a3:0000:0000:ac1f:8001");
		am.Login (name, password, "2001:0db8:0000:85a3:0000:0000:ac1f:8001");

		tr.commit ();
		getchar();
	}
	catch (std::exception e)
	{
		std::cerr << e.what ();
		getchar();
	}

	return 0;
}
