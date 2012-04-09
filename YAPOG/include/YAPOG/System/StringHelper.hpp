#ifndef YAPOG_STRINGHELPER_HPP
# define YAPOG_STRINGHELPER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  class StringHelper
  {
      DISALLOW_COPY(StringHelper);

    public:

      template <typename T>
      static String ToString (const T& value);

    private:

      StringHelper ();
      ~StringHelper ();
  };
} // namespace yap

# include "YAPOG/System/StringHelper.hxx"

#endif // YAPOG_STRINGHELPER_HPP
