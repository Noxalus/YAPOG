#ifndef YAPOG_COLLECTION_SET_HPP
# define YAPOG_COLLECTION_SET_HPP

# include <set>

# include "YAPOG/Macros.hpp"

namespace yap
{
  template <typename T>
  class LessComparator;

  namespace collection
  {
    template <typename T, typename C = std::less<T>>
    class Set
    {
      public:

        typedef T DataType;
        typedef C ComparatorType;
        typedef std::set<DataType, ComparatorType> InnerType;
        typedef typename InnerType::size_type SizeType;
        typedef typename InnerType::iterator ItType;
        typedef typename InnerType::const_iterator ConstItType;

        Set ();

        Set (const Set<T, C>& copy);

        Set& operator= (const Set<T, C>& copy);

        ItType begin ();
        ConstItType begin () const;
        ItType Begin ();
        ConstItType Begin () const;

        ItType end ();
        ConstItType end () const;
        ItType End ();
        ConstItType End () const;

        bool Add (const T& data);
        void Add (const Set<T, C>& data);

        bool Contains (const T& data) const;
        bool Contains (const Set<T, C>& data) const;

        bool Remove (const T& data);

        void Clear ();

        bool IsEmpty () const;
        SizeType Count () const;

      private:

        InnerType data_;
    };
  } // namespace collection
} // namespace yap

# include "YAPOG/Collection/Set.hxx"

#endif // YAPOG_COLLECTION_SET_HPP
