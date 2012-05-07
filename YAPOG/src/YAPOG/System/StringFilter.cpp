#include <regex>
#include "YAPOG/System/StringFilter.hpp"

namespace yap
{
  bool StringFilter::IsAlpha (String& str)
  {
    std::regex rx("[^[:alpha:]]");
    return !regex_search (str.begin(), str.end(), rx);
  }

  bool StringFilter::IsNumeric (String& str)
  {
    std::regex rx("[^[:digit:]]");
    return !regex_search (str.begin(), str.end(), rx);
  }

  bool StringFilter::ContainSpecial (String& str)
  {
    return (!IsAlpha (str) && !IsNumeric (str));
  }

  bool StringFilter::ContainNumeric (String& str)
  {

  }

  bool StringFilter::ContainAlpha (String& str)
  {

  }
} // !namespace yap