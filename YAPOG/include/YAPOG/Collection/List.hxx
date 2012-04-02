#ifndef YAPOG_LIST_HXX
# define YAPOG_LIST_HXX

# include <algorithm>

namespace yap
{
  namespace collection
  {
    template <typename T>
    inline List<T>::List ()
      : data_ ()
    {
    }

    template <typename T>
    inline List<T>::List (const List<T>& copy)
    {
      *this = copy;
    }

    template <typename T>
    inline List<T>& List<T>::operator= (const List<T>& copy)
    {
      if (&copy == this)
        return *this;

      data_ = copy.data_;

      return *this;
    }

    template <typename T>
    inline typename List<T>::ItType List<T>::begin ()
    {
      return data_.begin ();
    }

    template <typename T>
    inline typename List<T>::ConstItType List<T>::begin () const
    {
      return data_.begin ();
    }

    template <typename T>
    inline typename List<T>::ItType List<T>::Begin ()
    {
      return begin ();
    }

    template <typename T>
    inline typename List<T>::ConstItType List<T>::Begin () const
    {
      return begin ();
    }

    template <typename T>
    inline typename List<T>::ItType List<T>::end ()
    {
      return data_.end ();
    }

    template <typename T>
    inline typename List<T>::ConstItType List<T>::end () const
    {
      return data_.end ();
    }

    template <typename T>
    inline typename List<T>::ItType List<T>::End ()
    {
      return end ();
    }

    template <typename T>
    inline typename List<T>::ConstItType List<T>::End () const
    {
      return end ();
    }

    template <typename T>
    inline void List<T>::Add (const T& data)
    {
      data_.push_back (data);
    }

    template <typename T>
    inline void List<T>::Add (const List<T>& data)
    {
      data_.insert (End (), data.Begin (), data.End ());
    }

    template <typename T>
    inline void List<T>::AddFront (const T& data)
    {
      data_.push_front (data);
    }

    template <typename T>
    inline void List<T>::AddFront (const List<T>& data)
    {
      data_.insert (Begin (), data.Begin (), data.End ());
    }

    template <typename T>
    inline bool List<T>::Contains (const T& data) const
    {
      return std::find (Begin (), End (), data) != End ();
    }

    template <typename T>
    inline bool List<T>::Contains (const List<T>& data) const
    {
      for (const T& t : *this)
        if (Contains (t))
          return true;

      return false;
    }

    template <typename T>
    inline void List<T>::Remove (const T& data)
    {
      data_.remove (data);
    }

    template <typename T>
    inline void List<T>::RemoveFront ()
    {
      if (IsEmpty ())
        return;

      data_.pop_front ();
    }

    template <typename T>
    inline void List<T>::RemoveBack ()
    {
      if (IsEmpty ())
        return;

      data_.pop_back ();
    }

    template <typename T>
    inline void List<T>::Clear ()
    {
      data_.clear ();
    }

    template <typename T>
    inline bool List<T>::IsEmpty () const
    {
      return data_.empty ();
    }

    template <typename T>
    inline typename List<T>::SizeType List<T>::Count () const
    {
      return data_.size ();
    }
  } // namespace collection
} // namespace yap

#endif // YAPOG_LIST_HXX
