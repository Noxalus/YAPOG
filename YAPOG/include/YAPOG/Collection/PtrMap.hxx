#ifndef YAPOG_PTRMAP_HXX
# define YAPOG_PTRMAP_HXX

namespace yap
{
  template <typename K, typename V>
  inline PtrMap<K, V>::~PtrMap ()
  {
  }

  template <typename K, typename V>
  inline void PtrMap<K, V>::Add (const K& key, V* value)
  {
    Map<K, DataPtrType>::Add (key, DataPtrType (value));
  }
} // namespace yap

#endif // YAPOG_PTRMAP_HXX
