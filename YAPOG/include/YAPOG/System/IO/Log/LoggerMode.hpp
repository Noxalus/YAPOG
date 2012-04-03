#ifndef YAPOG_LOGGERMODE_HPP
# define YAPOG_LOGGERMODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IOStream.hpp"

namespace yap
{
  class YAPOG_LIB LoggerMode
  {
      DISALLOW_COPY(LoggerMode);

    public:

      LoggerMode ();
      virtual ~LoggerMode ();

      virtual OStream& GetPrefix (OStream& oStream) = 0;
      virtual OStream& GetSuffix (OStream& oStream) = 0;
  };
} // namespace yap

#endif // YAPOG_LOGGERMODE_HPP
