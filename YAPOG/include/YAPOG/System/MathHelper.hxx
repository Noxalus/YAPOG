#ifndef YAPOG_MATHHELPER_HXX
# define YAPOG_MATHHELPER_HXX

# include <algorithm>

namespace yap
{
  template <typename T>
  bool MathHelper::Max (const T& left, const T& right)
  {
    return std::max (left, right);
  }

  template <typename T>
  bool MathHelper::Min (const T& left, const T& right)
  {
    return std::min (left, right);
  }
} // namespace yap

#endif // YAPOG_MATHHELPER_HXX
