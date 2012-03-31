#ifndef YAPOG_TIMELOGGERMODE_HPP
# define YAPOG_TIMELOGGERMODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/LoggerMode.hpp"

namespace yap
{
  class TimeLoggerMode : public LoggerMode
  {
    public:

      virtual ~TimeLoggerMode ();

      virtual OStream& GetPrefix (OStream& oStream);
      virtual OStream& GetSuffix (OStream& oStream);
  };
} // namespace yap

#endif // YAPOG_TIMELOGGERMODE_HPP
