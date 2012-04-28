#ifndef YAPOG_MATHHELPER_HXX
# define YAPOG_MATHHELPER_HXX

# include <algorithm>

namespace yap
{
  template <typename T>
  T MathHelper::Max (const T& left, const T& right)
  {
    return std::max (left, right);
  }

  template <typename T>
  T MathHelper::Min (const T& left, const T& right)
  {
    return std::min (left, right);
  }

  template <typename T>
  T MathHelper::Clamp (const T& value, const T& min, const T& max)
  {
    return value < min ? min : (value > max ? max : value);
  }

  template <typename T>
  T MathHelper::Floor (const T& number)
  {
    return std::floor (number);
  }

  template <typename T1, typename T2>
  int MathHelper::Pow (const T1& number, const T2& pow)
  {
    return std::pow (number, pow);
  }

} // namespace yap

#endif // YAPOG_MATHHELPER_HXX
