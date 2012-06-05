#ifndef YAPOG_MAPEVENTMANAGER_HPP
# define YAPOG_MAPEVENTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Collection/Set.hpp"
# include "YAPOG/Game/World/Map/MapEventContextTriggerComparator.hpp"
# include "YAPOG/Game/World/Map/MapEvent.hpp"

namespace yap
{
  class DynamicWorldObject;
  class MapEventContext;
  class BoundingBox;
  class CollidableArea;

  class MapEventManager : public IUpdateable
  {
      DISALLOW_COPY(MapEventManager);

      typedef collection::Map<
        MapEvent*,
        collection::Set<
          MapEventContext*,
          MapEventContextTriggerComparator>> EventTriggeringType;
      /// Map<Object, Map<Source Event, Set<Event context (Trigger...)>>>
      typedef collection::Map<
        const DynamicWorldObject*,
        EventTriggeringType> ObjectEventsType;

    public:

      MapEventManager ();
      ~MapEventManager ();

      void SetCollidableArea (CollidableArea* collidableArea);

      void UpdateObject (DynamicWorldObject& object);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      bool AddEventEntry (
        const DynamicWorldObject* object,
        MapEvent* event,
        MapEventContext* eventContext);
      bool RemoveEventEntry (
        const DynamicWorldObject* object,
        MapEvent* event,
        MapEventContext* eventContext);

      void UpdateObjectOut (const DynamicWorldObject& object);
      void UpdateObjectIn (DynamicWorldObject& object);

      bool CallEvent (
        MapEvent::Type type,
        const Time& dt,
        MapEventContext& eventContext);

      ObjectEventsType events_;

      CollidableArea* collidableArea_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTMANAGER_HPP
