#ifndef YAPOG_EVENTTRIGGERBOUNDINGBOXCOLLECTION_HPP
# define YAPOG_EVENTTRIGGERBOUNDINGBOXCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/BoundingBoxCollection.hpp"

namespace yap
{
  class DynamicWorldObject;
  class MapEventQueue;

  class YAPOG_LIB EventTriggerBoundingBoxCollection : public BoundingBoxCollection
  {
      DISALLOW_ASSIGN(EventTriggerBoundingBoxCollection);

    public:

      EventTriggerBoundingBoxCollection ();
      virtual ~EventTriggerBoundingBoxCollection ();

      EventTriggerBoundingBoxCollection (
        const EventTriggerBoundingBoxCollection& copy);

      void AddEventTriggerBoundingBox (BoundingBox* boundingBox);
      void RemoveEventTriggerBoundingBox (BoundingBox* boundingBox);

      void SetCollidableArea (
        DynamicWorldObject& parent,
        CollidableArea* collidableArea);

      void GetEventsCollidingWith (
        const CollidableArea& collidableArea,
        MapEventQueue& events) const;

    private:

      virtual void HandleAddBoundingBoxToCollidableArea (
        BoundingBox* boundingBox);
      virtual void HandleRemoveBoundingBoxFromCollidableArea (
        BoundingBox* boundingBox);

      DynamicWorldObject* parent_;
  };
} // namespace yap

#endif // YAPOG_EVENTTRIGGERBOUNDINGBOXCOLLECTION_HPP
