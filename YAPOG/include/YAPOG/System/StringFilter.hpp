#ifndef YAPOG_STRING_FILTER_HPP
# define YAPOG_STRING_FILTER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class YAPOG_LIB StringFilter
  {
      DISALLOW_COPY(StringFilter);

    public:

      static bool IsNumeric (const String& str);

    private:

      static bool CheckRegex (const String& str, const String& regexExp);

      StringFilter ();
      ~StringFilter ();
  };
} // namespace yap

#endif /* !YAPOG_STRING_FILTER_HPP */
