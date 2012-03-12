#ifndef YAPOG_ARRAY_HPP
# define YAPOG_ARRAY_HPP

# include <vector>
# include <memory>

# include "YAPOG/Export.hpp"

namespace yap
{
  template <typename T>
  class YAPOG_LIB Array
  {
    public:

      typedef T DataType;
      typedef std::vector<DataType> InnerType;
      typedef typename InnerType::size_type SizeType;
      typedef typename InnerType::iterator It;
      typedef typename InnerType::const_iterator ConstIt;

      Array ();
      virtual ~Array ();

      It begin ();
      ConstIt begin () const;
      It Begin ();
      ConstIt Begin () const;

      It end ();
      ConstIt end () const;
      It End ();
      ConstIt End () const;

      void Add (const T& data);
      void Add (const Array<T>& data);

      void Remove ();

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
