#include "YAPOG/System/IO/Log/CountLoggerMode.hpp"

namespace yap
{
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
