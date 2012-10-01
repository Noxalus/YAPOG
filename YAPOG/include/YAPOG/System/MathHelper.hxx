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

  template <typename T1, typename T2>
  T1 MathHelper::Sqrt (const T1& number, const T2& pow)
  {
    T1 result = number;

    for (int i = 0; i < pow; i++)
      result = std::sqrt (result);

    return result;
  }

  template <typename T>
  T MathHelper::Abs (const T& value)
  {
    return value < 0 ? -value : value;
  }

  template <typename T>
  T MathHelper::Cos (const T& angle)
  {
    return std::cos (angle);
  }

  template <typename T>
  T MathHelper::Sin (const T& angle)
  {
    return std::sin (angle);
  }

  template <typename T>
  static T Lerp (const T& start, const T& end, float perccent)
  {
    return (start + percent * (end - start));
  }

} // namespace yap

#endif // YAPOG_MATHHELPER_HXX
