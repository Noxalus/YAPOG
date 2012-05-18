#include <vector>

#include <boost/algorithm/string.hpp>

#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  void StringHelper::Split (
    const String& str,
    const String& delimiters,
    collection::Array<String>& result)
  {
    std::vector<String> resultVector;
    boost::split (resultVector, str, boost::is_any_of (delimiters));

    for (const String& str : resultVector)
      result.Add (str);
  }
} // namespace yap
