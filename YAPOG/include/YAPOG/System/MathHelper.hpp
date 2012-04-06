#ifndef YAPOG_MATHHELPER_HPP
# define YAPOG_MATHHELPER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct MathHelper
  {
      template <typename T>
      static bool Max (const T& left, const T& right);

      template <typename T>
      static bool Min (const T& left, const T& right);
  };
} // namespace yap

# include "YAPOG/System/MathHelper.hxx"

#endif // YAPOG_MATHHELPER_HPP
