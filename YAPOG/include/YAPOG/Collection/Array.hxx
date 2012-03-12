#ifndef ARRAY_HXX
# define ARRAY_HXX

namespace yap
{
  template <typename T>
  Array<T>::Array ()
    : data_ ()
  {
  }

  template <typename T>
  Array<T>::~Array ()
  {
  }

  template <typename T>
  typename Array<T>::It Array<T>::begin ()
  {
    return data_.begin ();
  }

  template <typename T>
  typename Array<T>::ConstIt Array<T>::begin () const
  {
    return data_.begin ();
  }

  template <typename T>
  typename Array<T>::It Array<T>::Begin ()
  {
    return begin ();
  }

  template <typename T>
  typename Array<T>::ConstIt Array<T>::Begin () const
  {
    return begin ();
  }

  template <typename T>
  typename Array<T>::It Array<T>::end ()
  {
    return data_.end ();
  }

  template <typename T>
  typename Array<T>::ConstIt Array<T>::end () const
  {
    return data_.end ();
  }

  template <typename T>
  typename Array<T>::It Array<T>::End ()
  {
    return end ();
  }

  template <typename T>
  typename Array<T>::ConstIt Array<T>::End () const
  {
    return end ();
  }

  template <typename T>
  void Array<T>::Add (const T& data)
  {
    data_.push_back (data);
  }

  template <typename T>
  void Array<T>::Add (const Array<T>& data)
  {
    data_.insert (End (), data.Begin (), data.End ());
  }

  template <typename T>
  void Array<T>::Remove ()
  {
    if (IsEmpty ())
      return;

    data_.pop_back ();
  }

  template <typename T>
  void Array<T>::Clear ()
  {
    data_.clear ();
  }

  template <typename T>
  bool Array<T>::IsEmpty () const
  {
    return data_.empty ();
  }

  template <typename T>
  typename Array<T>::SizeType Array<T>::Count () const
  {
    return data_.size ();
  }

  template <typename T>
  const T& Array<T>::operator[] (Array<T>::SizeType index) const
  {
    return data_[index];
  }

  template <typename T>
  T& Array<T>::operator[] (Array<T>::SizeType index)
  {
    return data_[index];
  }
} /// namespace yap

#endif /// !ARRAY_HXX
