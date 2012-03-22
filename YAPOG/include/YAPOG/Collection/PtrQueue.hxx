#ifndef YAPOG_PTRQUEUE_HXX
# define YAPOG_PTRQUEUE_HXX

namespace yap
{
  template <typename T>
  inline PtrQueue<T>::~PtrQueue ()
  {
  }

  template <typename T>
  inline void PtrQueue<T>::Enqueue (T* data)
  {
    Queue<DataPtrType>::Enqueue (DataPtrType (data));
  }

  template <typename T>
  inline T* PtrQueue<T>::Dequeue (T* data)
  {
    DataPtrType dataPtr;

    return Queue<DataPtrType>::Dequeue (dataPtr).get ();
  }
} // namespace yap

#endif // YAPOG_PTRQUEUE_HXX
