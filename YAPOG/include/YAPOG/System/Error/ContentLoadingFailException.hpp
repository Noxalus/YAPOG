#ifndef YAPOG_CONTENTLOADINGFAILEXCEPTION_HPP
# define YAPOG_CONTENTLOADINGFAILEXCEPTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  class YAPOG_LIB ContentLoadingFailException : public Exception
  {
    public:

      explicit ContentLoadingFailException (const String& contentName);
      virtual ~ContentLoadingFailException () throw ();

      ContentLoadingFailException (const ContentLoadingFailException& copy);
      ContentLoadingFailException& operator= (
        const ContentLoadingFailException& copy);

    private:

      static const String DEFAULT_MESSAGE_PREFIX;
      static const String DEFAULT_MESSAGE_SUFFIX;
  };
} // namespace yap

#endif // YAPOG_CONTENTLOADINGFAILEXCEPTION_HPP
