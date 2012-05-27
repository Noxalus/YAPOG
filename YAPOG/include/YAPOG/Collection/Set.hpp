#ifndef YAPOG_COLLECTION_SET_HPP
# define YAPOG_COLLECTION_SET_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  namespace collection
  {
    template <typename T>
    class Set
    {
      public:

        typedef T DataType;
        typedef std::set<DataType> InnerType;
        typedef typename InnerType::size_type SizeType;
        typedef typename InnerType::iterator ItType;
        typedef typename InnerType::const_iterator ConstItType;

        Set ();
        explicit Set (const LessComparator<T>& comparator);

        Set (const Set<T>& copy);

        Set& operator= (const Set<T>& copy);

        ItType begin ();
        ConstItType begin () const;
        ItType Begin ();
        ConstItType Begin () const;

        ItType end ();
        ConstItType end () const;
        ItType End ();
        ConstItType End () const;

        void Add (const T& data);
        void Add (const Set<T>& data);

        bool Contains (const T& data) const;
        bool Contains (const Set<T>& data) const;

        void Remove (const T& data);

        void Clear ();

        bool IsEmpty () const;
        SizeType Count () const;

      private:

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

#endif // YAPOG_COLLECTION_SET_HPP
