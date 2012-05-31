#include "YAPOG/Database/DatabaseManager.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
	DatabaseManager::DatabaseManager ()
		: dl_ (nullptr)
	{
	}

	DatabaseManager::~DatabaseManager ()
	{
	}

  void DatabaseManager::Connect ()
  {
    try
		{
			connection_.connect(
        "dbname=yapog "
        "user=postgres "
        "password=COUCOU "
        "port=5432");
		}
		catch (pgs::pg_excpt e)
		{
      std::cerr << e.full_error_txt ();
		}
  }

	void DatabaseManager::SetLogStream (OStream& os)
	{
		if (dl_ != nullptr)
			YAPOG_THROW("The log stream is already set !");

		dl_ = new DatabaseLogger (os);
	}

	pgs::pg_cnx& DatabaseManager::GetConnection ()
	{
		return connection_;
	}

	DatabaseLogger& DatabaseManager::GetDatabaseLogger ()
	{
		return *dl_;
	}

} // namespace yap