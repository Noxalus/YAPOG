#ifndef YAPOG_ARRAY_HPP
# define YAPOG_ARRAY_HPP

# include <vector>

# include "YAPOG/Export.hpp"

namespace yap
{
  /// @class Array
  /// @brief Wrapper for std::vector.
  /// To use in case of frequent back add/deletion or frequent single access.
  template <typename T>
  class YAPOG_LIB Array
  {
    public:

      typedef T DataType;
      typedef std::vector<DataType> InnerType;
      typedef typename InnerType::size_type SizeType;
      typedef typename InnerType::iterator ItType;
      typedef typename InnerType::const_iterator ConstItType;

      Array ();
      virtual ~Array ();

      Array (const Array<T>& copy);
      Array& operator= (const Array<T>& copy);

      ItType begin ();
      ConstItType begin () const;
      ItType Begin ();
      ConstItType Begin () const;

      ItType end ();
      ConstItType end () const;
      ItType End ();
      ConstItType End () const;

      void Add (const T& data);
      void Add (const Array<T>& data);

      bool Contains (const T& data) const;
      bool Contains (const Array<T>& data) const;

      void Remove (const T& data);
      void RemoveBack ();

      void Clear ();

      bool IsEmpty () const;
      SizeType Count () const;

      const T& operator[] (SizeType index) const;
      T& operator[] (SizeType index);

    private:

      InnerType data_;
  };
} /// namespace yap

# include "YAPOG/Collection/Array.hxx"

#endif /// !YAPOG_ARRAY_HPP
