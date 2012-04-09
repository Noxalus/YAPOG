#ifndef YAPOG_DATETIME_HPP
# define YAPOG_DATETIME_HPP

# include <boost/date_time/posix_time/posix_time.hpp>
# include <boost/date_time/posix_time/posix_time_io.hpp>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB DateTime
  {
    public:

      typedef boost::posix_time::ptime InnerTimeType;

      explicit DateTime (const InnerTimeType& time);

      DateTime (const DateTime& copy);
      DateTime& operator= (const DateTime& copy);

      String ToFullDateString () const;

    private:

      InnerTimeType time_;
  };
} // namespace yap

#endif // YAPOG_DATETIME_HPP
