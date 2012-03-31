#include "YAPOG/System/IO/Log/TimeLoggerMode.hpp"
#include "YAPOG/System/Time/DateTimeHelper.hpp"

namespace yap
{
  TimeLoggerMode::~TimeLoggerMode ()
  {
  }

  OStream& TimeLoggerMode::GetPrefix (OStream& oStream)
  {
    oStream << "["
            << DateTimeHelper::Now ().ToFullDateString ()
            << "] ";

    return oStream;
  }

  OStream& TimeLoggerMode::GetSuffix (OStream& oStream)
  {
    return oStream;
  }
} // namespace yap
