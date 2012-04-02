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

      explicit Exception (const String& message);
      virtual ~Exception () throw ();

      Exception (const Exception& copy);
      Exception& operator= (const Exception& copy);

      OStream& GetMessage (OStream& oStream) const throw ();

    private:

      String message_;
  };
} // namespace yap

#endif // YAPOG_EXCEPTION_HPP
