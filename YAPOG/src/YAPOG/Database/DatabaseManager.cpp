#include <iostream>
#include "YAPOG/Database/DatabaseManager.hpp"

namespace yap
{
	DatabaseManager::DatabaseManager ()
	{
		try
		{
			connexion_.connect("dbname=yapog user=postgres password=COUCOU");
		}
		catch (pg_excpt e)
		{
			std::cerr << e.errmsg ();
		}
	}

	DatabaseManager::~DatabaseManager ()
	{
	}

	pg_cnx DatabaseManager::GetConnexion ()
	{
		return connexion_;
	}
} // namespace yap