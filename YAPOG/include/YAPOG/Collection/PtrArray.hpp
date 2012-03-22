#ifndef YAPOG_PTRARRAY_HPP
# define YAPOG_PTRARRAY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  template <typename T>
  class YAPOG_LIB PtrArray : public Array<typename T::PtrType>
  {
    public:

      typedef typename T::PtrType DataPtrType;

      virtual ~PtrArray ();

      void Add (T* data);
      void Remove (T* data);

      bool Contains (T* data) const;
  };
} // namespace yap

# include "YAPOG/Collection/PtrArray.hxx"

#endif // YAPOG_PTRARRAY_HPP
