#include "YAPOG/System/StringFilter.hpp"

#include <boost/regex.hpp>

namespace yap
{
  bool StringFilter::IsNumeric (const String& str)
  {
    return CheckRegex (str, "\\d");
  }

  bool StringFilter::CheckRegex (const String& str, const String& regexExp)
  {
    return boost::regex_match (str, boost::regex (regexExp));
  }
} // !namespace yap
