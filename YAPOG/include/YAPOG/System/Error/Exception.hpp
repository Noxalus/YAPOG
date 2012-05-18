#ifndef YAPOG_EXCEPTION_HPP
# define YAPOG_EXCEPTION_HPP

# include <exception>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IOStream.hpp"
# include "YAPOG/System/String.hpp"

# define YAPOG_EXCEPTION_MESSAGE_PREFIX                                 \
  "[YAPOG exception][" __FILE__ ":" +                                   \
  yap::StringHelper::ToString (__LINE__) + "] "
# define YAPOG_THROW(MESSAGE)                                   \
  throw yap::Exception (YAPOG_EXCEPTION_MESSAGE_PREFIX MESSAGE)

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
