#ifndef YAPOG_STRINGHELPER_HXX
# define YAPOG_STRINGHELPER_HXX

# include <sstream>

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
} // namespace yap

#endif // YAPOG_STRINGHELPER_HXX
