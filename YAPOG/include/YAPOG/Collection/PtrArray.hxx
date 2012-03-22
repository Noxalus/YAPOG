#ifndef YAPOG_PTRARRAY_HXX
# define YAPOG_PTRARRAY_HXX

# include <algorithm>

namespace yap
{
  template <typename T>
  inline PtrArray<T>::~PtrArray ()
  {
  }

  template <typename T>
  inline void PtrArray<T>::Add (T* data)
  {
    Array<DataPtrType>::Add (DataPtrType (data));
  }

  template <typename T>
  inline void PtrArray<T>::Remove (T* data)
  {
    typename Array<DataPtrType>::ItType toRemove = std::find_if (
      this->Begin (),
      this->End (),
      [&] (const DataPtrType& it) { return it.get () == data; });

    if (toRemove == this->End ())
      return;

    this->data_.erase (toRemove);
  }

  template <typename T>
  inline bool PtrArray<T>::Contains (T* data) const
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

#endif // !YAPOG_PTRARRAY_HXX
