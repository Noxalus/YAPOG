#include "YAPOG/System/IO/Log/DatabaseLogger.hpp"
#include "YAPOG/System/IO/IWriterVisitor.hpp"
#include "YAPOG/System/IO/IWriterConstVisitor.hpp"

namespace yap
{
	DatabaseLogger::DatabaseLogger (OStream& os)
		: Logger (os)
	{
		Activate (true);
	}

	DatabaseLogger::~DatabaseLogger ()
	{
	}


	void DatabaseLogger::Accept (IWriterVisitor& visitor)
	{
		visitor.Visit (*this);
	}

	void DatabaseLogger::Accept (IWriterConstVisitor& visitor) const
	{
		visitor.Visit (*this);
	}
} // namespace yap
