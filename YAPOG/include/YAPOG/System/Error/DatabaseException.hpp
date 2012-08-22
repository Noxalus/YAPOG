#ifndef YAPOG_DATABASEEXCEPTION_HPP
# define YAPOG_DATABASEEXCEPTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Error/Exception.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB DatabaseException 
    : public Exception
  {
    public:
      explicit DatabaseException (const String& message);
      virtual ~DatabaseException () throw ();
  };
} // namespace yap

#endif // YAPOG_DATABASEEXCEPTION_HPP
