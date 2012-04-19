#ifndef YAPOG_DATETIMEHELPER_HPP
# define YAPOG_DATETIMEHELPER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/DateTime.hpp"

namespace yap
{
  class YAPOG_LIB DateTimeHelper
  {
      DISALLOW_COPY(DateTimeHelper);

    public:

      static DateTime Now ();

    private:

      DateTimeHelper ();
      ~DateTimeHelper ();
  };
} // namespace yap

#endif // YAPOG_DATETIMEHELPER_HPP
