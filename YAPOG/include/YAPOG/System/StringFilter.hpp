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
    static bool IsAlpha (String& str);
    static bool IsNumeric (String& str);
    static bool ContainSpecial (String& str);
    static bool ContainNumeric (String& str);
    static bool ContainAlpha (String& str);

  };
} // namespace yap

#endif /* !YAPOG_STRING_FILTER_HPP */