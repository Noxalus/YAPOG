#ifndef YAPOG_ICLONABLE_HPP
# define YAPOG_ICLONABLE_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IClonable
  {
      virtual IClonable* Clone () const = 0;
  };
} // namespace yap

#endif // YAPOG_ICLONABLE_HPP
