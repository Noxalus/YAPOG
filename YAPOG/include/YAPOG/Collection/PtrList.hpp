#ifndef YAPOG_PTRLIST_HPP
# define YAPOG_PTRLIST_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  template <typename T>
  class YAPOG_LIB PtrList : public List<typename T::PtrType>
  {
    public:

      typedef typename T::PtrType DataPtrType;

      virtual ~PtrList ();

      void Add (T* data);
      void AddFront (T* data);
      void Remove (T* data);

      bool Contains (T* data) const;
  };
} // namespace yap

# include "YAPOG/Collection/PtrList.hxx"

#endif // YAPOG_PTRLIST_HPP
