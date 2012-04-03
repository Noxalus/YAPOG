#include "YAPOG/System/IO/Log/CountLoggerMode.hpp"

namespace yap
{
  const int CountLoggerMode::DEFAULT_COUNT = 0;

  CountLoggerMode::CountLoggerMode ()
    : LoggerMode ()
    , currentCount_ (DEFAULT_COUNT)
  {
  }

  CountLoggerMode::~CountLoggerMode ()
  {
  }

  OStream& CountLoggerMode::GetPrefix (OStream& oStream)
  {
    oStream << "["
            << currentCount_++
            << "] ";

    return oStream;
  }

  OStream& CountLoggerMode::GetSuffix (OStream& oStream)
  {
    return oStream;
  }
} // namespace yap
