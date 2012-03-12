#ifndef YAPOG_PTRARRAY_HPP
# define YAPOG_PTRARRAY_HPP

# include <memory>

# include "YAPOG/Export.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  template <typename T>
  struct YAPOG_LIB PtrArray : public Array<std::shared_ptr<T>>
  {
    typedef std::shared_ptr<T> DataType;
  };
} /// namespace yap

#endif /// !YAPOG_PTRARRAY_HPP
