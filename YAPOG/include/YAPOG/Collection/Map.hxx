#ifndef YAPOG_MAP_HXX
# define YAPOG_MAP_HXX

namespace yap
{
  template <typename K, typename V>
  inline Map<K, V>::Map ()
    : data_ ()
  {
  }

  template <typename K, typename V>
  inline Map<K, V>::~Map ()
  {
  }

  template <typename K, typename V>
  inline Map<K, V>::Map (const Map<K, V>& copy)
  {
    *this = copy;
  }

  template <typename K, typename V>
  inline Map<K, V>& Map<K, V>::operator= (const Map<K, V>& copy)
  {
    if (&copy == this)
      return *this;

    data_ = copy.data_;

    return *this;
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ItType Map<K, V>::begin ()
  {
    return data_.begin ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ConstItType Map<K, V>::begin () const
  {
    return data_.begin ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ItType Map<K, V>::Begin ()
  {
    return begin ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ConstItType Map<K, V>::Begin () const
  {
    return begin ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ItType Map<K, V>::end ()
  {
    return data_.end ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ConstItType Map<K, V>::end () const
  {
    return data_.end ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ItType Map<K, V>::End ()
  {
    return end ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::ConstItType Map<K, V>::End () const
  {
    return end ();
  }

  template <typename K, typename V>
  inline void Map<K, V>::Add (const K& key, const V& value)
  {
    data_.insert (DataType (key, value));
  }

  template <typename K, typename V>
  inline void Map<K, V>::Add (const Map<K, V>& data)
  {
    data_.insert (data.Begin (), data.End ());
  }

  template <typename K, typename V>
  inline bool Map<K, V>::Contains (const K& key) const
  {
    return data_.find (key) != End ();
  }

  template <typename K, typename V>
  inline void Map<K, V>::Remove (const K& key)
  {
    data_.erase (key);
  }

  template <typename K, typename V>
  inline void Map<K, V>::Clear ()
  {
    data_.clear ();
  }

  template <typename K, typename V>
  inline bool Map<K, V>::IsEmpty () const
  {
    return data_.empty ();
  }

  template <typename K, typename V>
  inline typename Map<K, V>::SizeType Map<K, V>::Count () const
  {
    return data_.size ();
  }

  template <typename K, typename V>
  inline V& Map<K, V>::operator[] (const K& key)
  {
    return data_.find (key)->second;
  }

  template <typename K, typename V>
  inline const V& Map<K, V>::operator[] (const K& key) const
  {
    return data_.find (key)->second;
  }
} // namespace yap

#endif // YAPOG_MAP_HXX
