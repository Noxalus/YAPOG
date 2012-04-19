#ifndef YAPOG_ITABLE_HPP
# define YAPOG_ITABLE_HPP

# include <SFML/Graphics/Color.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/Time/DateTime.hpp"
# include "YAPOG/Database/DatabaseManager.hpp"

struct IDrawingContext;

struct ITable
{
	virtual ~ITable () {};

	virtual yap::ID Add (yap::DatabaseManager dM) const = 0;
	virtual bool Remove (yap::DatabaseManager dM) const = 0;

	virtual int GetInt (yap::DatabaseManager dM, const yap::String& columnName) const = 0;
	virtual yap::DateTime GetDate (yap::DatabaseManager dM, const yap::String& columnName) const = 0;
};

#endif // YAPOG_ITABLE_HPP