#include <iostream>
#include "Database/Tables/AccountTable.hpp"
#include "tmp/Server.hpp"
#include "YAPOG/Database/DatabaseManager.hpp"
#include <iostream>

int main ()
{
	std::cout << "Server is starting..."
		<< std::endl;

	try
	{
		yap::DatabaseManager dM;
		AccountTable at;
		AccountTable at2;
		pg_stream s ("TRUNCATE account", dM.GetConnexion ());
		at.SetName ("COUCOU");
		at2.SetName ("Test");
		at.Add (dM);
		//at2.Add (dM);
		getchar();
	}
	catch (std::exception e)
	{
		std::cerr << e.what ();
		getchar();
	}

	return 0;
}
