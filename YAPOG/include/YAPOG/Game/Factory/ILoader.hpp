#ifndef YAPOG_ILOADER_HPP
# define YAPOG_ILOADER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class ID;

  template <typename T>
  struct ILoader
  {
      virtual ~ILoader () {}

      T* Load (const ID& id);
  };
} // namespace yap

#endif // YAPOG_ILOADER_HPP
