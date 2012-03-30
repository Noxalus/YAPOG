#include "YAPOG/System/IO/Log/DebugLogger.hpp"

namespace yap
{
  DebugLogger::DebugLogger ()
    : Logger (std::cout)
  {
#ifdef NDEBUG
    Activate (false);
#else
    Activate (true);
#endif // NDEBUG
  }

  DebugLogger::~DebugLogger ()
  {
  }

  DebugLogger& DebugLogger::Instance ()
  {
    static DebugLogger instance;

    return instance;
  }
} // namespace yap
