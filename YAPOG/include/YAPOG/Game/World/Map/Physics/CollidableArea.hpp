#ifndef YAPOG_COLLIDABLEAREA_HPP
# define YAPOG_COLLIDABLEAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"

namespace yap
{
  struct ICollidable;

  class YAPOG_LIB CollidableArea
  {
      DISALLOW_COPY(CollidableArea);

    public:

      virtual ~CollidableArea ();

      void SetSize (uint width, uint height);

      void AddCollidable (ICollidable* collidable);

    protected:

      CollidableArea ();

      virtual void HandleSetSize (uint width, uint height);

      virtual void HandleAddCollidable (ICollidable* collidable) = 0;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREA_HPP
