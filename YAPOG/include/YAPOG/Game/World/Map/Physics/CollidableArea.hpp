#ifndef YAPOG_COLLIDABLEAREA_HPP
# define YAPOG_COLLIDABLEAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/IntTypes.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"
# include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"

namespace yap
{
  struct ICollidable;

  class WorldObject;
  class DynamicWorldObject;
  class MapEventQueue;

  class YAPOG_LIB CollidableArea
  {
      DISALLOW_COPY(CollidableArea);

    public:

      virtual ~CollidableArea ();

      void SetSize (const Vector2& size);

      void AddPhysicsCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo);
      void RemovePhysicsCollidable (ICollidable* collidable);

      void AddEventCollidable (
        ICollidable* collidable,
        const MapEventInfo::PtrType& mapEventInfo);
      void RemoveEventCollidable (ICollidable* collidable);

      virtual bool CollidesWithObject (
        const WorldObject& object,
        const Vector2& offset) const = 0;

      virtual void GetEventsCollidingWithObject (
        const DynamicWorldObject& object,
        MapEventQueue& events) const = 0;

    protected:

      CollidableArea ();

      virtual void HandleSetSize (const Vector2& size);

      virtual void HandleAddPhysicsCollidable (
        ICollidable* collidable,
        const MapCollidableInfo::PtrType& mapCollidableInfo) = 0;
      virtual void HandleRemovePhysicsCollidable (ICollidable* collidable) = 0;

      virtual void HandleAddEventCollidable (
        ICollidable* collidable,
        const MapEventInfo::PtrType& mapEventInfo) = 0;
      virtual void HandleRemoveEventCollidable (ICollidable* collidable) = 0;

    private:

      Vector2 size_;
  };
} // namespace yap

#endif // YAPOG_COLLIDABLEAREA_HPP
