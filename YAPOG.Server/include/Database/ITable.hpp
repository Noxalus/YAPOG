#ifndef YAPOG_ITABLE_HPP
# define YAPOG_ITABLE_HPP

# include <SFML/Graphics/Color.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/System/Time/DateTime.hpp"

struct IDrawingContext;

struct ITable
{
	virtual ~ITable () {};

	virtual yap::ID Add () const = 0;
	virtual bool Remove () const = 0;

	virtual int GetInt (const yap::String& columnName) const = 0;
	virtual yap::DateTime GetDate (const yap::String& columnName) const = 0;
};

#endif // YAPOG_ITABLE_HPP