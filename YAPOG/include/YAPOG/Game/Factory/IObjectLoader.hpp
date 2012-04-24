#ifndef YAPOG_IOBJECTLOADER_HPP
# define YAPOG_IOBJECTLOADER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"

namespace yap
{
  struct ILoadable;

  struct IObjectLoader
  {
      virtual ~IObjectLoader () {}

      virtual ILoadable* Load (
        IReader& reader,
        const String& rootNodeName) = 0;
  };
} // namespace yap

#endif // YAPOG_IOBJECTLOADER_HPP
