#ifndef YAPOG_COUNTLOGGERMODE_HPP
# define YAPOG_COUNTLOGGERMODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IO/Log/LoggerMode.hpp"

namespace yap
{
  class CountLoggerMode : public LoggerMode
  {
    public:

      virtual ~CountLoggerMode ();

      virtual OStream& GetPrefix (OStream& oStream);
      virtual OStream& GetSuffix (OStream& oStream);

    private:

      int currentCount_;
  };
} // namespace yap

#endif // YAPOG_COUNTLOGGERMODE_HPP
