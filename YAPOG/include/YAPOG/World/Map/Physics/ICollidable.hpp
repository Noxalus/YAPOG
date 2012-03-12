#ifndef YAPOG_ICOLLIDABLE_HPP
# define YAPOG_ICOLLIDABLE_HPP

# include "YAPOG/Vector2.hpp"

namespace yap
{
  struct ICollidable
  {
      virtual ~ICollidable () {}

      virtual const Vector2& GetPosition () const = 0;
      virtual const Vector2& GetSize () const = 0;

      virtual void Move (const Vector2& offset) = 0;
  };
} /// namespace yap

#endif /// !YAPOG_ICOLLIDABLE_HPP
