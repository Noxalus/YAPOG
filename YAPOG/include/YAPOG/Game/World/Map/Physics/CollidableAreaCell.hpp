#ifndef YAPOG_COLLIDABLEAREACELL_HPP
# define YAPOG_COLLIDABLEAREACELL_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"
# include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"

namespace yap
{
  struct ICollidable;

  class WorldObject;
  class DynamicWorldObject;
  class MapEventQueue;

  class CollidableAreaCell
  {
      DISALLOW_COPY(CollidableAreaCell);

    public:

      CollidableAreaCell ();

      void AddPhysicsCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo);
      void RemovePhysicsCollidable (ICollidable* collidable);

      void AddEventCollidable (
        ICollidable* collidable,
        const MapEventInfo::PtrType& mapEventInfo);
      void RemoveEventCollidable (ICollidable* collidable);

      bool CollidesWithObject (
        const WorldObject& object,
        const Vector2& offset) const;

      void GetEventsCollidingWithObject (
        DynamicWorldObject& object,
        MapEventQueue& events) const;

      void Clear ();

    private:

      collection::Map<
        ICollidable*,
        MapCollidableInfo::PtrType> physicsCollidables_;

      collection::Map<
        ICollidable*,
        MapEventInfo::PtrType> eventCollidables_;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREACELL_HPP
