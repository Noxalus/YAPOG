#ifndef YAPOG_QUEUE_HXX
# define YAPOG_QUEUE_HXX

namespace yap
{
  namespace collection
  {
    template <typename T>
    inline Queue<T>::Queue ()
      : data_ ()
    {
    }

    template <typename T>
    inline Queue<T>::Queue (const Queue<T>& copy)
      : data_ (copy.data_)
    {
    }

    template <typename T>
    inline Queue<T>& Queue<T>::operator= (const Queue<T>& copy)
    {
      if (&copy == this)
        return *this;

      data_ = copy.data_;

      return *this;
    }

    template <typename T>
    inline void Queue<T>::Enqueue (const T& data)
    {
      data_.push (data);
    }

    template <typename T>
    inline T& Queue<T>::Dequeue (T& data)
    {
      data = data_.front ();

      data_.pop ();

      return data;
    }

    template <typename T>
    inline bool Queue<T>::IsEmpty () const
    {
      return data_.empty ();
    }

    template <typename T>
    inline typename Queue<T>::SizeType Queue<T>::Count () const
    {
      return data_.size ();
    }

    template <typename T>
    inline void Queue<T>::Clear ()
    {
      InnerType ().swap (data_);
    }
  } // namespace collection
} // namespace yap

#endif // YAPOG_QUEUE_HXX
