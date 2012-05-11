#ifndef YAPOG_DATABASEMANAGER_HPP
# define YAPOG_DATABASEMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/System/IO/Log/DatabaseLogger.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "pgstream/pgstream.hpp"

namespace yap
{
	class YAPOG_LIB DatabaseManager
	{
		DISALLOW_COPY(DatabaseManager);
	public:
		DatabaseManager ();
		~DatabaseManager ();

		pgs::pg_cnx& GetConnection ();
		DatabaseLogger& GetDatabaseLogger ();
		void SetLogStream (OStream& os);
	private:
		pgs::pg_cnx connection_;
		DatabaseLogger* dl_;
	};
} // namespace yap

#endif // YAPOG_DATABASEMANAGER_HPP
