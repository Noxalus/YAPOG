#ifndef YAPOG_EXCEPTION_HPP
# define YAPOG_EXCEPTION_HPP

# include <exception>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB Exception : public std::exception
  {
    public:

      Exception ();
      Exception (const String& message);
      Exception (const Exception& innerException);
      Exception (const String& message, const Exception& innerException);

      virtual ~Exception () throw ();

      OStream& GetMessage (OStream& oStream) const throw ();

    private:

      const String message_;
      const Exception* innerException_;
  };
} // namespace yap

#endif // YAPOG_EXCEPTION_HPP
