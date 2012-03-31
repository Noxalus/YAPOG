#ifndef YAPOG_INVALIDMETHODCALLEXCEPTION_HPP
# define YAPOG_INVALIDMETHODCALLEXCEPTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  class YAPOG_LIB InvalidMethodCallException : public Exception
  {
    public:

      InvalidMethodCallException (const String& methodName);
      InvalidMethodCallException (
        const String& methodName,
        const Exception& innerException);
      virtual ~InvalidMethodCallException () throw ();

    private:

      static const String DEFAULT_MESSAGE_PREFIX;
      static const String DEFAULT_MESSAGE_SUFFIX;
  };
} // namespace yap

#endif // YAPOG_INVALIDMETHODCALLEXCEPTION_HPP
