#ifndef YAPOG_PTRLIST_HXX
# define YAPOG_PTRLIST_HXX

# include <algorithm>

namespace yap
{
  template <typename T>
  inline PtrList<T>::~PtrList ()
  {
  }

  template <typename T>
  inline void PtrList<T>::Add (T* data)
  {
    List<DataPtrType>::Add (DataPtrType (data));
  }

  template <typename T>
  inline void PtrList<T>::AddFront (T* data)
  {
    List<DataPtrType>::AddFront (DataPtrType (data));
  }

  template <typename T>
  inline void PtrList<T>::Remove (T* data)
  {
    this->data_.remove_if (
      [&] (const DataPtrType& it) { return it.get () == data; });
  }

  template <typename T>
  inline bool PtrList<T>::Contains (T* data) const
  {
    return std::find_if (
      this->Begin (),
      this->End (),
      [&] (const DataPtrType& it)
      {
        return it.get () == data;
      }) != this->End ();
  }
} // namespace yap

#endif // YAPOG_PTRLIST_HXX
