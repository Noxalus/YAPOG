#ifndef YAPOG_EVENTBOUNDINGBOXCOLLECTION_HPP
# define YAPOG_EVENTBOUNDINGBOXCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/BoundingBoxCollection.hpp"
# include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  class DynamicWorldObject;
  class MapEvent;

  class EventBoundingBoxCollection : public BoundingBoxCollection
  {
      DISALLOW_ASSIGN(EventBoundingBoxCollection);

    public:

      EventBoundingBoxCollection ();
      virtual ~EventBoundingBoxCollection ();

      EventBoundingBoxCollection (const EventBoundingBoxCollection& copy);

      void AddEventBoundingBox (
        BoundingBox* boundingBox,
        MapEvent* event);
      void RemoveEventBoundingBox (BoundingBox* boundingBox);

      void SetCollidableArea (
        DynamicWorldObject& parent,
        CollidableArea* collidableArea);

    private:

      virtual void HandleAddBoundingBoxToCollidableArea (
        BoundingBox* boundingBox);
      virtual void HandleRemoveBoundingBoxFromCollidableArea (
        BoundingBox* boundingBox);

      DynamicWorldObject* parent_;

      collection::Map<BoundingBox*, MapEvent*> eventBoundingBoxes_;
  };
} // namespace yap

#endif // YAPOG_EVENTBOUNDINGBOXCOLLECTION_HPP
