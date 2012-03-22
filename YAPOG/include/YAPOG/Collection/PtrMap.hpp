#ifndef YAPOG_PTRMAP_HPP
# define YAPOG_PTRMAP_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  template <typename K, typename V>
  class YAPOG_LIB PtrMap : public Map<K, typename V::PtrType>
  {
    public:

      typedef typename V::PtrType DataPtrType;

      virtual ~PtrMap ();

      void Add (const K& key, V* value);
  };
} // namespace yap

# include "YAPOG/Collection/PtrMap.hxx"

#endif // YAPOG_PTRMAP_HPP
