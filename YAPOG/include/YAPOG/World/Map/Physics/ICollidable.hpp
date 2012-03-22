#ifndef YAPOG_ICOLLIDABLE_HPP
# define YAPOG_ICOLLIDABLE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Vector2.hpp"

namespace yap
{
  struct YAPOG_LIB ICollidable
  {
      DECLARE_PTR_TYPE(ICollidable);

      virtual ~ICollidable () {}

      virtual const Vector2& GetPosition () const = 0;
      virtual const Vector2& GetSize () const = 0;

      virtual void Move (const Vector2& offset) = 0;
      virtual void Scale (const Vector2& factor) = 0;
  };
} // namespace yap

#endif // YAPOG_ICOLLIDABLE_HPP
