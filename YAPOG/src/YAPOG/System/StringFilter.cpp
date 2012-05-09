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
    std::regex rx("[^[:digit:]^[:alpha:]]");
    return regex_search (str.begin(), str.end(), rx);
  }

  bool StringFilter::ContainNumeric (String& str)
  {
    std::regex rx("[[:digit:]]");
    return regex_search (str.begin(), str.end(), rx);
  }

  bool StringFilter::ContainAlpha (String& str)
  {
    std::regex rx("[[:alpha:]]");
    return regex_search (str.begin(), str.end(), rx);
  }
} // !namespace yap