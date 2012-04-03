#ifndef YAPOG_TIMELOGGERMODE_HPP
# define YAPOG_TIMELOGGERMODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/LoggerMode.hpp"

namespace yap
{
  class YAPOG_LIB TimeLoggerMode : public LoggerMode
  {
      DISALLOW_COPY(TimeLoggerMode);

    public:

      TimeLoggerMode ();
      virtual ~TimeLoggerMode ();

      virtual OStream& GetPrefix (OStream& oStream);
      virtual OStream& GetSuffix (OStream& oStream);
  };
} // namespace yap

#endif // YAPOG_TIMELOGGERMODE_HPP
