#ifndef YAPOG_COUNTLOGGERMODE_HPP
# define YAPOG_COUNTLOGGERMODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/LoggerMode.hpp"

namespace yap
{
  class YAPOG_LIB CountLoggerMode : public LoggerMode
  {
      DISALLOW_COPY(CountLoggerMode);

    public:

      CountLoggerMode ();
      virtual ~CountLoggerMode ();

      virtual OStream& GetPrefix (OStream& oStream);
      virtual OStream& GetSuffix (OStream& oStream);

    private:

      static const int DEFAULT_COUNT;

      int currentCount_;
  };
} // namespace yap

#endif // YAPOG_COUNTLOGGERMODE_HPP
