#ifndef YAPOG_LIST_HPP
# define YAPOG_LIST_HPP

# include <list>

# include "YAPOG/Export.hpp"

namespace yap
{
  /// @class List
  /// @brief Wrapper for std::list.
  template <typename T>
  class YAPOG_LIB List
  {
    public:

      typedef T DataType;
      typedef std::list<DataType> InnerType;
      typedef typename InnerType::size_type SizeType;
      typedef typename InnerType::iterator ItType;
      typedef typename InnerType::const_iterator ConstItType;

      List ();
      ~List ();

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

    private:

      InnerType data_;
  };
} /// namespace yap

# include "YAPOG/Collection/List.hxx"

#endif /// !YAPOG_LIST_HPP
