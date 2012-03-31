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

  InvalidMethodCallException::InvalidMethodCallException (
    const String& methodName,
    const Exception& innerException)
    : Exception (DEFAULT_MESSAGE_PREFIX +
                 methodName +
                 DEFAULT_MESSAGE_SUFFIX,
                 innerException)
  {
  }

  InvalidMethodCallException::~InvalidMethodCallException () throw ()
  {
  }
} // namespace yap
