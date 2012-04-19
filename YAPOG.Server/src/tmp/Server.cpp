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
		//pg_cnx cnx = dM.GetConnexion ();
		pg_stream s ("TRUNCATE account", dM.GetConnexion ());
		/*
		at.SetName ("COUCOU");
		at.Add (dM);
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
