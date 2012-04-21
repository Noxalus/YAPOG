#ifndef YAPOG_ILOADER_HPP
# define YAPOG_ILOADER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ILoadable;

  class ID;

  struct ILoader
  {
      virtual ~ILoader () {}

      virtual ILoadable* Load (const ID& id) = 0;
  };
} // namespace yap

#endif // YAPOG_ILOADER_HPP
