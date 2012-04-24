#ifndef YAPOG_IOBJECTIDLOADER_HPP
# define YAPOG_IOBJECTIDLOADER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ILoadable;

  class ID;

  struct IObjectIDLoader
  {
      virtual ~IObjectIDLoader () {}

      virtual ILoadable* Load (const ID& id) = 0;
  };
} // namespace yap

#endif // YAPOG_IOBJECTIDLOADER_HPP
