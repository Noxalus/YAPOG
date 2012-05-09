#ifndef YAPOG_IINSERTABLE_HPP
# define YAPOG_IINSERTABLE_HPP

# include "YAPOG/Database/DatabaseManager.hpp"

struct IInsertTable
{
	virtual ~IInsertTable () {};

	virtual bool Add (yap::DatabaseManager& databaseManager) = 0;
};

#endif // YAPOG_ITABLE_HPP