#ifndef YAPOG_DATABASEMANAGER_HPP
# define YAPOG_DATABASEMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "pgstream/pgstream.hpp"

namespace yap
{
	class YAPOG_LIB DatabaseManager
	{
	public:
		DatabaseManager ();
		~DatabaseManager ();

		pg_cnx& GetConnexion ();
	private:
		pg_cnx connexion_;
	};
} // namespace yap

#endif // YAPOG_DATABASEMANAGER_HPP
