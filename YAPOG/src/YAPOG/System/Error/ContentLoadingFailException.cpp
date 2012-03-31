#include "YAPOG/System/Error/ContentLoadingFailException.hpp"

namespace yap
{
  const String ContentLoadingFailException::DEFAULT_MESSAGE_PREFIX =
    "Failed to load content: `";
  const String ContentLoadingFailException::DEFAULT_MESSAGE_SUFFIX =
    "'";

  ContentLoadingFailException::ContentLoadingFailException (
    const String& contentName)
    : Exception (DEFAULT_MESSAGE_PREFIX +
                 contentName +
                 DEFAULT_MESSAGE_SUFFIX)
  {
  }

  ContentLoadingFailException::ContentLoadingFailException (
    const String& contentName,
    const Exception& innerException)
    : Exception (DEFAULT_MESSAGE_PREFIX +
                 contentName +
                 DEFAULT_MESSAGE_SUFFIX,
                 innerException)
  {
  }

  ContentLoadingFailException::~ContentLoadingFailException () throw ()
  {
  }
} // namespace yap
