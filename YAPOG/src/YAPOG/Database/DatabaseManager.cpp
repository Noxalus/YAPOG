#include <iostream>
#include "YAPOG/Database/DatabaseManager.hpp"

namespace yap
{
	DatabaseManager::DatabaseManager ()
		: dl_ (nullptr)
	{
		try
		{
			connection_.connect("dbname=yapog user=postgres password=COUCOU port=5432");
		}
		catch (pg_excpt e)
		{
			std::cerr << e.errmsg ();
		}
	}

	DatabaseManager::~DatabaseManager ()
	{
	}

	void DatabaseManager::SetLogStream (OStream& os)
	{
		if (dl_ != nullptr)
			throw Exception ("The log stream is already set !");

		dl_ = new DatabaseLogger (os);
	}

	pg_cnx& DatabaseManager::GetConnection ()
	{
		return connection_;
	}

	DatabaseLogger& DatabaseManager::GetDatabaseLogger ()
	{
		return *dl_;
	}

} // namespace yap