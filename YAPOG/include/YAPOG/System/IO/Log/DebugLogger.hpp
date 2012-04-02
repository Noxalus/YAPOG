#ifndef YAPOG_DEBUGLOGGER_HPP
# define YAPOG_DEBUGLOGGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/Logger.hpp"

namespace yap
{
  class YAPOG_LIB DebugLogger : public Logger
  {
      DISALLOW_COPY(DebugLogger);

    public:

      static DebugLogger& Instance ();

      virtual void Accept (IWriterVisitor& visitor);
      virtual void Accept (IWriterConstVisitor& visitor) const;

    private:

      DebugLogger ();
      virtual ~DebugLogger ();
  };
} // namespace yap

#endif // YAPOG_DEBUGLOGGER_HPP
