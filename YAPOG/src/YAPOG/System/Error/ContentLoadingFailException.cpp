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

  ContentLoadingFailException::~ContentLoadingFailException () throw ()
  {
  }

  ContentLoadingFailException::ContentLoadingFailException (
    const ContentLoadingFailException& copy)
    : Exception (copy)
  {
  }

  ContentLoadingFailException& ContentLoadingFailException::operator= (
    const ContentLoadingFailException& copy)
  {
    if (this == &copy)
      return *this;

    Exception::operator= (copy);

    return *this;
  }
} // namespace yap
