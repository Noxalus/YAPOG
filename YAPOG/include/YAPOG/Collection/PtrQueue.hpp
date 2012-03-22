#ifndef YAPOG_PTRQUEUE_HPP
# define YAPOG_PTRQUEUE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Queue.hpp"

namespace yap
{
  template <typename T>
  class YAPOG_LIB PtrQueue : public Queue<typename T::PtrType>
  {
    public:

      typedef typename T::PtrType DataPtrType;

      virtual ~PtrQueue ();

      void Enqueue (T* data);
      T* Dequeue (T* data);
  };
} // namespace yap

# include "YAPOG/Collection/PtrQueue.hxx"

#endif // YAPOG_PTRQUEUE_HPP
