#ifndef YAPOG_LESSCOMPARATOR_HXX
# define YAPOG_LESSCOMPARATOR_HXX

namespace yap
{
  template <typename T>
  inline LessComparator<T>::LessComparator ()
  {
  }

  template <typename T>
  inline LessComparator<T>::~LessComparator ()
  {
  }

  template <typename T>
  inline LessComparator<T>::LessComparator (const LessComparator<T>& copy)
  {
  }

  template <typename T>
  inline LessComparator<T>& LessComparator<T>::operator= (
    const LessComparator<T>& copy)
  {
    return *this;
  }

  template <typename T>
  inline bool LessComparator<T>::operator() (
    const T& left,
    const T& right) const
  {
    return Compare (left, right) < 0;
  }

  template <typename T>
  inline int LessComparator<T>::Compare (const T& left, const T& right) const
  {
    return HandleCompare (left, right);
  }
} // namespace yap

#endif // YAPOG_LESSCOMPARATOR_HXX
