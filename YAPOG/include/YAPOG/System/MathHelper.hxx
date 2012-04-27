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
  T MathHelper::Floor (const T& number)
  {
    return std::floor (number);
  }
} // namespace yap

#endif // YAPOG_MATHHELPER_HXX
