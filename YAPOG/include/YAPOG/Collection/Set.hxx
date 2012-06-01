#ifndef YAPOG_SET_HXX
# define YAPOG_SET_HXX

# include "YAPOG/Macros.hpp"

namespace yap
{
  namespace collection
  {
    template <typename T, typename C>
    inline Set<T, C>::Set ()
      : data_ ()
    {
    }

    template <typename T, typename C>
    inline Set<T, C>::Set (const Set<T, C>& copy)
      : data_ (copy.data_)
    {
    }

    template <typename T, typename C>
    inline Set<T, C>& Set<T, C>::operator= (const Set<T, C>& copy)
    {
      if (&copy == this)
        return *this;

      data_ = copy.data_;

      return *this;
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ItType Set<T, C>::begin ()
    {
      return data_.begin ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ConstItType Set<T, C>::begin () const
    {
      return data_.begin ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ItType Set<T, C>::Begin ()
    {
      return begin ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ConstItType Set<T, C>::Begin () const
    {
      return begin ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ItType Set<T, C>::end ()
    {
      return data_.end ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ConstItType Set<T, C>::end () const
    {
      return data_.end ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ItType Set<T, C>::End ()
    {
      return end ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::ConstItType Set<T, C>::End () const
    {
      return end ();
    }

    template <typename T, typename C>
    inline void Set<T, C>::Add (const T& data)
    {
      data_.insert (data);
    }

    template <typename T, typename C>
    inline void Set<T, C>::Add (const Set<T, C>& data)
    {
      data_.insert (data.Begin (), data.End ());
    }

    template <typename T, typename C>
    inline bool Set<T, C>::Contains (const T& data) const
    {
      return data_.find (data) != End ();
    }

    template <typename T, typename C>
    inline bool Set<T, C>::Contains (const Set<T, C>& data) const
    {
      for (const T& t : *this)
        if (Contains (t))
          return true;

      return false;
    }

    template <typename T, typename C>
    inline void Set<T, C>::Remove (const T& data)
    {
      data_.erase (data);
    }

    template <typename T, typename C>
    inline void Set<T, C>::Clear ()
    {
      data_.clear ();
    }

    template <typename T, typename C>
    inline bool Set<T, C>::IsEmpty () const
    {
      return data_.empty ();
    }

    template <typename T, typename C>
    inline typename Set<T, C>::SizeType Set<T, C>::Count () const
    {
      return data_.size ();
    }
  } // namespace collection
} // namespace yap

#endif // YAPOG_SET_HXX
