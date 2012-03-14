#ifndef YAPOG_STATE_HXX
# define YAPOG_STATE_HXX

namespace yap
{
  template <typename T>
  inline State<T>::State ()
    : value_ ()
  {
  }

  template <typename T>
  inline State<T>::State (const T& value)
    : value_ (value)
  {
  }

  template <typename T>
  inline State<T>::State (const State<T>& copy)
    : value_ (copy.value_)
  {
  }

  template <typename T>
  inline State<T>& State<T>::operator= (const State<T>& copy)
  {
    if (this == &copy)
      return *this;

    value_ = copy.value_;

    return *this;
  }

  template <typename T>
  inline bool State<T>::operator== (const State<T>& rhs) const
  {
    return value_ == rhs.value_;
  }

  template <typename T>
  inline bool State<T>::operator== (const T& rhs) const
  {
    return value_ == rhs;
  }

  template <typename T>
  inline bool State<T>::operator!= (const State<T>& rhs) const
  {
    return !(*this == rhs);
  }

  template <typename T>
  inline bool State<T>::operator!= (const T& rhs) const
  {
    return !(*this == rhs);
  }

  template <typename T>
  inline State<T>::operator const T& () const
  {
    return value_;
  }

  template <typename T>
  inline bool operator== (const T& lhs, const State<T>& rhs)
  {
    return rhs == lhs;
  }

} /// namespace yap

#endif /// !YAPOG_STATE_HXX
