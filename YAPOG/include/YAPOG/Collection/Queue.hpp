#ifndef YAPOG_QUEUE_HPP
# define YAPOG_QUEUE_HPP

# include <queue>

# include "YAPOG/Macros.hpp"

namespace yap
{
  namespace collection
  {
    template <typename T>
    class Queue
    {
      public:

        typedef T DataType;
        typedef std::queue<DataType> InnerType;
        typedef typename InnerType::size_type SizeType;

        Queue ();

        Queue (const Queue& copy);
        Queue& operator= (const Queue<T>& copy);

        void Enqueue (const T& data);
        T& Dequeue (T& data);

        bool IsEmpty () const;
        SizeType Count () const;

      private:

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

# include "YAPOG/Collection/Queue.hxx"

#endif // YAPOG_QUEUE_HPP
