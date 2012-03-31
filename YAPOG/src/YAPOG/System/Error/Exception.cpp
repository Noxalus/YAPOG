#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  Exception::Exception ()
    : std::exception ()
    , message_ ()
    , innerException_ (nullptr)
  {
  }

  Exception::Exception (const String& message)
    : std::exception ()
    , message_ (message)
    , innerException_ (nullptr)
  {
  }

  Exception::Exception (const Exception& innerException)
    : std::exception ()
    , message_ ()
    , innerException_ (&innerException)
  {
  }

  Exception::Exception (const String& message, const Exception& innerException)
    : std::exception ()
    , message_ (message)
    , innerException_ (&innerException)
  {
  }

  Exception::~Exception () throw ()
  {
  }

  OStream& Exception::GetMessage (OStream& oStream) const throw ()
  {
    oStream << message_;

    if (innerException_ != nullptr)
      return innerException_->GetMessage (oStream);

    return oStream;
  }
} // namespace yap
