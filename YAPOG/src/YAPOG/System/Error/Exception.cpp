#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  Exception::Exception (const String& message)
    : std::exception ()
    , message_ (message)
  {
  }

  Exception::~Exception () throw ()
  {
  }

  Exception::Exception (const Exception& copy)
    : std::exception (copy)
    , message_ (copy.message_)
  {
  }

  Exception& Exception::operator= (const Exception& copy)
  {
    if (this == &copy)
      return *this;

    message_ = copy.message_;

    return *this;
  }

  OStream& Exception::GetMessage (OStream& oStream) const throw ()
  {
    oStream << message_;

    return oStream;
  }
} // namespace yap
