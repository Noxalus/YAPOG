#ifndef YAPOG_PTRLIST_HPP
# define YAPOG_PTRLIST_HPP

# include <memory>

# include "YAPOG/Export.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  template <typename T>
  struct YAPOG_LIB PtrList : public List<std::shared_ptr<T>>
  {
    typedef std::shared_ptr<T> DataType;
  };
} /// namespace yap

#endif /// !YAPOG_PTRLIST_HPP
