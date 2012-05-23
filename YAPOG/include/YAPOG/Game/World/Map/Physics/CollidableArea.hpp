#ifndef YAPOG_COLLIDABLEAREA_HPP
# define YAPOG_COLLIDABLEAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  struct ICollidable;

  class YAPOG_LIB CollidableArea
  {
      DISALLOW_COPY(CollidableArea);

    public:

      virtual ~CollidableArea ();

      void SetSize (const Vector2& size);

      void AddCollidable (ICollidable* collidable);

    protected:

      CollidableArea ();

      virtual void HandleSetSize (const Vector2& size);

      virtual void HandleAddCollidable (ICollidable* collidable) = 0;

    private:

      Vector2 size_;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREA_HPP
