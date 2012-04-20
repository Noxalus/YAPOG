#ifndef YAPOG_IINSERTABLE_HPP
# define YAPOG_IINSERTABLE_HPP

# include "YAPOG/Database/DatabaseManager.hpp"

struct IInsertTable
{
	virtual ~IInsertTable () {};

	virtual void Add (yap::DatabaseManager& dM) const = 0;
};

#endif // YAPOG_ITABLE_HPP