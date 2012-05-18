#ifndef YAPOG_ICLONEABLE_HPP
# define YAPOG_ICLONEABLE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct YAPOG_LIB ICloneable
  {
      virtual ~ICloneable () {}

      virtual ICloneable* Clone () const = 0;
  };
} // namespace yap

#endif // YAPOG_ICLONEABLE_HPP
