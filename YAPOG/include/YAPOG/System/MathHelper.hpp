#ifndef YAPOG_MATHHELPER_HPP
# define YAPOG_MATHHELPER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class MathHelper
  {
      DISALLOW_COPY(MathHelper);

    public:

      template <typename T>
      static bool Max (const T& left, const T& right);

      template <typename T>
      static bool Min (const T& left, const T& right);

    private:

      MathHelper ();
      ~MathHelper ();
  };
} // namespace yap

# include "YAPOG/System/MathHelper.hxx"

#endif // YAPOG_MATHHELPER_HPP
