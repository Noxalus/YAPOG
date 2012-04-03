#ifndef YAPOG_INVALIDMETHODCALLEXCEPTION_HPP
# define YAPOG_INVALIDMETHODCALLEXCEPTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  class YAPOG_LIB InvalidMethodCallException : public Exception
  {
    public:

      explicit InvalidMethodCallException (const String& methodName);
      virtual ~InvalidMethodCallException () throw ();

      InvalidMethodCallException (const InvalidMethodCallException& copy);
      InvalidMethodCallException& operator= (
        const InvalidMethodCallException& copy);

    private:

      static const String DEFAULT_MESSAGE_PREFIX;
      static const String DEFAULT_MESSAGE_SUFFIX;
  };
} // namespace yap

#endif // YAPOG_INVALIDMETHODCALLEXCEPTION_HPP
