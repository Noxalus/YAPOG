#ifndef YAPOG_CONTENTLOADINGFAILEXCEPTION_HPP
# define YAPOG_CONTENTLOADINGFAILEXCEPTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  class YAPOG_LIB ContentLoadingFailException : public Exception
  {
    public:

      ContentLoadingFailException (const String& contentName);
      ContentLoadingFailException (
        const String& contentName,
        const Exception& innerException);
      virtual ~ContentLoadingFailException () throw ();

    private:

      static const String DEFAULT_MESSAGE_PREFIX;
      static const String DEFAULT_MESSAGE_SUFFIX;
  };
} // namespace yap

#endif // YAPOG_CONTENTLOADINGFAILEXCEPTION_HPP
