#ifndef YAPOG_DEBUGLOGGER_HPP
# define YAPOG_DEBUGLOGGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/Logger.hpp"

namespace yap
{
  class YAPOG_LIB DebugLogger : public Logger
  {
    public:

      DISALLOW_COPY(DebugLogger);

      static DebugLogger& Instance ();

    private:

      DebugLogger ();
      virtual ~DebugLogger ();
  };
} // namespace yap

#endif // YAPOG_DEBUGLOGGER_HPP
