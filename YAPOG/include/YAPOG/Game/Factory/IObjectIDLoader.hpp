#ifndef YAPOG_IOBJECTIDLOADER_HPP
# define YAPOG_IOBJECTIDLOADER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IIDLoadable;

  class ID;

  struct YAPOG_LIB IObjectIDLoader
  {
      virtual ~IObjectIDLoader () {}

      virtual IIDLoadable* Load (const ID& id) = 0;
  };
} // namespace yap

#endif // YAPOG_IOBJECTIDLOADER_HPP
