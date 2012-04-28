#ifndef YAPOG_MATHHELPER_HPP
# define YAPOG_MATHHELPER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class YAPOG_LIB MathHelper
  {
      DISALLOW_COPY(MathHelper);

    public:

      template <typename T>
      static T Max (const T& left, const T& right);

      template <typename T>
      static T Min (const T& left, const T& right);

      template <typename T>
      static T Floor (const T& number);

      template <typename T>
      static T Clamp (const T& value, const T& min, const T& max);

      template <typename T1, typename T2>
      static int Pow (const T1& number, const T2& pow);

    private:

      MathHelper ();
      ~MathHelper ();
  };
} // namespace yap

# include "YAPOG/System/MathHelper.hxx"

#endif // YAPOG_MATHHELPER_HPP
