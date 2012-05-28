#ifndef YAPOG_COLLIDABLEAREA_HPP
# define YAPOG_COLLIDABLEAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"

namespace yap
{
  struct ICollidable;

  class WorldObject;

  class YAPOG_LIB CollidableArea
  {
      DISALLOW_COPY(CollidableArea);

    public:

      virtual ~CollidableArea ();

      void SetSize (const Vector2& size);

      void AddCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo);
      void RemoveCollidable (ICollidable* collidable);

      virtual bool CollidesWithObject (const WorldObject& object) const = 0;
      virtual bool CollidesWithObject (
        const WorldObject& object,
        const Vector2& offset) const = 0;

    protected:

      CollidableArea ();

      virtual void HandleSetSize (const Vector2& size);

      virtual void HandleAddCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo) = 0;
      virtual void HandleRemoveCollidable (ICollidable* collidable) = 0;

    private:

      Vector2 size_;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREA_HPP
