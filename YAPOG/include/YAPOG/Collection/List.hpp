#ifndef YAPOG_LIST_HPP
# define YAPOG_LIST_HPP

# include <list>

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/LessComparator.hpp"

namespace yap
{
  namespace collection
  {
    template <typename T>
    class List
    {
      public:

        typedef T DataType;
        typedef std::list<DataType> InnerType;
        typedef typename InnerType::size_type SizeType;
        typedef typename InnerType::iterator ItType;
        typedef typename InnerType::const_iterator ConstItType;

        List ();

        List (const List<T>& copy);
        List& operator= (const List<T>& copy);

        ItType begin ();
        ConstItType begin () const;
        ItType Begin ();
        ConstItType Begin () const;

        ItType end ();
        ConstItType end () const;
        ItType End ();
        ConstItType End () const;

        void Add (const T& data);
        void Add (const List<T>& data);
        void AddFront (const T& data);
        void AddFront (const List<T>& data);

        bool Contains (const T& data) const;
        bool Contains (const List<T>& data) const;

        void Remove (const T& data);
        void RemoveFront ();
        void RemoveBack ();

        void Clear ();

        bool IsEmpty () const;
        SizeType Count () const;

        template <typename C>
        void Sort ();

      private:

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

# include "YAPOG/Collection/List.hxx"

#endif // YAPOG_LIST_HPP
