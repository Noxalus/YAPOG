#ifndef YAPOG_DATETIMEHELPER_HPP
# define YAPOG_DATETIMEHELPER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/Time/DateTime.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB DateTimeHelper
  {
      DISALLOW_COPY(DateTimeHelper);

    public:

      static DateTime Now ();
			static DateTime Parse (const yap::String& date);

    private:

      DateTimeHelper ();
      ~DateTimeHelper ();
  };
} // namespace yap

#endif // YAPOG_DATETIMEHELPER_HPP
