#ifndef YAPOG_MATRIX_HXX
# define YAPOG_MATRIX_HXX

namespace yap
{
  namespace collection
  {
    template <typename T>
    inline Matrix<T>::Matrix (
      SizeType width,
      SizeType height,
      const DataType& data)
      : width_ (width)
      , height_ (height)
      , data_ (width_ * height_, data)
    {
    }

    template <typename T>
    inline Matrix<T>::Matrix (const Matrix<T>& copy)
      : width_ (copy.width_)
      , height_ (copy.height_)
      , data_ (copy.data_)
    {
    }

    template <typename T>
    inline Matrix<T>& Matrix<T>::operator= (const Matrix<T>& copy)
    {
      if (&copy == this)
        return *this;

      data_ = copy.data_;

      return *this;
    }

    template <typename T>
    inline typename Matrix<T>::ItType Matrix<T>::begin ()
    {
      return data_.begin ();
    }

    template <typename T>
    inline typename Matrix<T>::ConstItType Matrix<T>::begin () const
    {
      return data_.begin ();
    }

    template <typename T>
    inline typename Matrix<T>::ItType Matrix<T>::Begin ()
    {
      return begin ();
    }

    template <typename T>
    inline typename Matrix<T>::ConstItType Matrix<T>::Begin () const
    {
      return begin ();
    }

    template <typename T>
    inline typename Matrix<T>::ItType Matrix<T>::end ()
    {
      return data_.end ();
    }

    template <typename T>
    inline typename Matrix<T>::ConstItType Matrix<T>::end () const
    {
      return data_.end ();
    }

    template <typename T>
    inline typename Matrix<T>::ItType Matrix<T>::End ()
    {
      return end ();
    }

    template <typename T>
    inline typename Matrix<T>::ConstItType Matrix<T>::End () const
    {
      return end ();
    }

    template <typename T>
    inline void Matrix<T>::Resize (
      SizeType width,
      SizeType height,
      const T& data)
    {
      Matrix<T> resized (width, height, data);

      for (SizeType y = 0; y < height_; ++y)
        for (SizeType x = 0; x < width_; ++x)
          resized (x, y) = this->operator() (x, y);

      *this = resized;
    }

    template <typename T>
    inline void Matrix<T>::Set (SizeType x, SizeType y, const T& data)
    {
      data_[GetIndex (x, y)] = data;
    }

    template <typename T>
    inline const T& Matrix<T>::operator() (SizeType x, SizeType y) const
    {
      return data_[GetIndex (x, y)];
    }

    template <typename T>
    inline T& Matrix<T>::operator() (SizeType x, SizeType y)
    {
      return data_[GetIndex (x, y)];
    }

    template <typename T>
    inline typename Matrix<T>::SizeType Matrix<T>::GetIndex (
      SizeType x,
      SizeType y) const
    {
      return y * width_ + x;
    }
  } // collection
} // namespace yap

#endif // YAPOG_MATRIX_HXX
