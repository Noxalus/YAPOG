#ifndef YAPOG_STRINGHELPER_HXX
# define YAPOG_STRINGHELPER_HXX

# include <sstream>

# include <boost/lexical_cast.hpp>

# include "YAPOG/Macros.hpp"

namespace yap
{
  template <typename T>
  inline String StringHelper::ToString (const T& value)
  {
    std::ostringstream oss;

    oss << value;

    return oss.str ();
  }

  template <typename T>
  inline T StringHelper::Parse (const String& str)
  {
    return boost::lexical_cast <T> (str);
  }
} // namespace yap

#endif // YAPOG_STRINGHELPER_HXX
