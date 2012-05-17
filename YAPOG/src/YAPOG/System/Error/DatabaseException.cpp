#include "YAPOG/System/Error/DatabaseException.hpp"

namespace yap
{
  DatabaseException::DatabaseException (const String& message)
    : Exception (message)
  {
  }

  DatabaseException::~DatabaseException () throw ()
  {
  }
} // namespace yap
