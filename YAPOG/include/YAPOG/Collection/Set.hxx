#ifndef YAPOG_SET_HXX
# define YAPOG_SET_HXX

# include "YAPOG/Macros.hpp"

namespace yap
{
  namespace collection
  {
    template <typename T>
    inline Set<T>::Set ()
      : data_ ()
    {
    }

    template <typename T>
    inline Set<T>::Set (const LessComparator<T>& comparator)
      : data_ (comparator)
    {
    }

    template <typename T>
    inline Set<T>::Set (const Set<T>& copy)
      : data_ (copy.data_)
    {
    }

    template <typename T>
    inline Set<T>& Set<T>::operator= (const Set<T>& copy)
    {
      if (&copy == this)
        return *this;

      data_ = copy.data_;

      return *this;
    }

    template <typename T>
    inline typename Set<T>::ItType Set<T>::begin ()
    {
      return data_.begin ();
    }

    template <typename T>
    inline typename Set<T>::ConstItType Set<T>::begin () const
    {
      return data_.begin ();
    }

    template <typename T>
    inline typename Set<T>::ItType Set<T>::Begin ()
    {
      return begin ();
    }

    template <typename T>
    inline typename Set<T>::ConstItType Set<T>::Begin () const
    {
      return begin ();
    }

    template <typename T>
    inline typename Set<T>::ItType Set<T>::end ()
    {
      return data_.end ();
    }

    template <typename T>
    inline typename Set<T>::ConstItType Set<T>::end () const
    {
      return data_.end ();
    }

    template <typename T>
    inline typename Set<T>::ItType Set<T>::End ()
    {
      return end ();
    }

    template <typename T>
    inline typename Set<T>::ConstItType Set<T>::End () const
    {
      return end ();
    }

    template <typename T>
    inline void Set<T>::Add (const T& data)
    {
      data_.insert (data);
    }

    template <typename T>
    inline void Set<T>::Add (const Set<T>& data)
    {
      data_.insert (data.Begin (), data.End ());
    }

    template <typename T>
    inline bool Set<T>::Contains (const T& data) const
    {
      return data_.find (data) != End ();
    }

    template <typename T>
    inline bool Set<T>::Contains (const Set<T>& data) const
    {
      for (const T& t : *this)
        if (Contains (t))
          return true;

      return false;
    }

    template <typename T>
    inline void Set<T>::Remove (const T& data)
    {
      data_.erase (data);
    }

    template <typename T>
    inline void Set<T>::Clear ()
    {
      data_.clear ();
    }

    template <typename T>
    inline bool Set<T>::IsEmpty () const
    {
      return data_.empty ();
    }

    template <typename T>
    inline typename Set<T>::SizeType Set<T>::Count () const
    {
      return data_.size ();
    }
  } // namespace collection
} // namespace yap

#endif // YAPOG_SET_HXX
