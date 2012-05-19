#ifndef YAPOG_ICOLLIDABLE_HPP
# define YAPOG_ICOLLIDABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/ISpatial3.hpp"

namespace yap
{
  struct YAPOG_LIB ICollidable : public ISpatial3
  {
      virtual ~ICollidable () {}
  };
} // namespace yap

#endif // YAPOG_ICOLLIDABLE_HPP
