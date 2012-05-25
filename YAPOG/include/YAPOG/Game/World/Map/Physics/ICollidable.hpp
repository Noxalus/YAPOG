#ifndef YAPOG_ICOLLIDABLE_HPP
# define YAPOG_ICOLLIDABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/ISpatial3.hpp"

namespace yap
{
  struct YAPOG_LIB ICollidable : public ISpatial3
  {
      virtual ~ICollidable () {}

      virtual bool CollidesWith (const ICollidable& other) const = 0;

//      virtual Vector2 GetDistance (
//        const ICollidable& other,
//        const Vector2& maxOffset) const = 0;
  };
} // namespace yap

#endif // YAPOG_ICOLLIDABLE_HPP
