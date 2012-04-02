#include "YAPOG/System/IO/Log/DebugLogger.hpp"
#include "YAPOG/System/IO/IWriterVisitor.hpp"
#include "YAPOG/System/IO/IWriterConstVisitor.hpp"

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

  void DebugLogger::Accept (IWriterVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void DebugLogger::Accept (IWriterConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }
} // namespace yap
