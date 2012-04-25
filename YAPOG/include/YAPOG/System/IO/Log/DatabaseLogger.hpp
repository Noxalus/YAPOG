#ifndef YAPOG_DATABASELOGGER_HPP
# define YAPOG_DATABASELOGGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/Logger.hpp"

namespace yap
{
	class YAPOG_LIB DatabaseLogger : public Logger
	{
		DISALLOW_COPY(DatabaseLogger);

	public:
		DatabaseLogger (OStream& os);
		virtual ~DatabaseLogger ();

		virtual void Accept (IWriterVisitor& visitor);
		virtual void Accept (IWriterConstVisitor& visitor) const;
	};
} // namespace yap

#endif // YAPOG_DATABASELOGGER_HPP
