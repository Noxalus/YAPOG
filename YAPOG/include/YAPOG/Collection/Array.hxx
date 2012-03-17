#ifndef YAPOG_ARRAY_HXX
# define YAPOG_ARRAY_HXX

# include <algorithm>

namespace yap
{
  template <typename T>
  inline Array<T>::Array ()
    : data_ ()
  {
  }

  template <typename T>
  inline Array<T>::~Array ()
  {
  }

  template <typename T>
  inline Array<T>::Array (const Array<T>& copy)
    : data_ (copy.data_)
  {
  }

  template <typename T>
  inline Array<T>& Array<T>::operator= (const Array<T>& copy)
  {
    if (&copy == this)
      return *this;

    data_ = copy.data_;

    return *this;
  }

  template <typename T>
  inline typename Array<T>::ItType Array<T>::begin ()
  {
    return data_.begin ();
  }

  template <typename T>
  inline typename Array<T>::ConstItType Array<T>::begin () const
  {
    return data_.begin ();
  }

  template <typename T>
  inline typename Array<T>::ItType Array<T>::Begin ()
  {
    return begin ();
  }

  template <typename T>
  inline typename Array<T>::ConstItType Array<T>::Begin () const
  {
    return begin ();
  }

  template <typename T>
  inline typename Array<T>::ItType Array<T>::end ()
  {
    return data_.end ();
  }

  template <typename T>
  inline typename Array<T>::ConstItType Array<T>::end () const
  {
    return data_.end ();
  }

  template <typename T>
  inline typename Array<T>::ItType Array<T>::End ()
  {
    return end ();
  }

  template <typename T>
  inline typename Array<T>::ConstItType Array<T>::End () const
  {
    return end ();
  }

  template <typename T>
  inline void Array<T>::Add (const T& data)
  {
    data_.push_back (data);
  }

  template <typename T>
  inline void Array<T>::Add (const Array<T>& data)
  {
    data_.insert (End (), data.Begin (), data.End ());
  }

  template <typename T>
  inline bool Array<T>::Contains (const T& data) const
  {
    return std::find (Begin (), End (), data) != End ();
  }

  template <typename T>
  inline bool Array<T>::Contains (const Array<T>& data) const
  {
    for (const T& t : *this)
      if (Contains (t))
        return true;

    return false;
  }

  template <typename T>
  inline void Array<T>::Remove (const T& data)
  {
    ItType toRemove = std::find (Begin (), End (), data);

    if (toRemove == End ())
      return;

    data_.erase (toRemove);
  }

  template <typename T>
  inline void Array<T>::RemoveBack ()
  {
    if (IsEmpty ())
      return;

    data_.pop_back ();
  }

  template <typename T>
  inline void Array<T>::Clear ()
  {
    data_.clear ();
  }

  template <typename T>
  inline bool Array<T>::IsEmpty () const
  {
    return data_.empty ();
  }

  template <typename T>
  inline typename Array<T>::SizeType Array<T>::Count () const
  {
    return data_.size ();
  }

  template <typename T>
  inline const T& Array<T>::operator[] (Array<T>::SizeType index) const
  {
    return data_[index];
  }

  template <typename T>
  inline T& Array<T>::operator[] (Array<T>::SizeType index)
  {
    return data_[index];
  }
} /// namespace yap

#endif /// !YAPOG_ARRAY_HXX
