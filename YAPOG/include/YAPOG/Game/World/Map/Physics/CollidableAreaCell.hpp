#ifndef YAPOG_COLLIDABLEAREACELL_HPP
# define YAPOG_COLLIDABLEAREACELL_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"

namespace yap
{
  struct ICollidable;

  class WorldObject;

  class CollidableAreaCell
  {
      DISALLOW_COPY(CollidableAreaCell);

    public:

      CollidableAreaCell ();

      void AddPhysicsCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo);
      void RemovePhysicsCollidable (ICollidable* collidable);

      bool CollidesWithObject (const WorldObject& object) const;
      bool CollidesWithObject (
        const WorldObject& object,
        const Vector2& offset) const;

      void Clear ();

    private:

      collection::Map<ICollidable*,
                      MapCollidableInfo::PtrType> physicsCollidables_;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREACELL_HPP
