#include "YAPOG/System/Error/InvalidMethodCallException.hpp"

namespace yap
{
  const String InvalidMethodCallException::DEFAULT_MESSAGE_PREFIX =
    "Invalid call to: `";
  const String InvalidMethodCallException::DEFAULT_MESSAGE_SUFFIX =
    "'";

  InvalidMethodCallException::InvalidMethodCallException (
    const String& methodName)
    : Exception (DEFAULT_MESSAGE_PREFIX +
                 methodName +
                 DEFAULT_MESSAGE_SUFFIX)
  {
  }

  InvalidMethodCallException::~InvalidMethodCallException () throw ()
  {
  }

  InvalidMethodCallException::InvalidMethodCallException (
    const InvalidMethodCallException& copy)
    : Exception (copy)
  {
  }

  InvalidMethodCallException& InvalidMethodCallException::operator= (
    const InvalidMethodCallException& copy)
  {
    if (this == &copy)
      return *this;

    Exception::operator= (copy);

    return *this;
  }
} // namespace yap
