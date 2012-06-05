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

  /// @todo
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

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    private:

      void AddObjectEntry (const DynamicWorldObject* object);
      void RemoveObjectEntry (const DynamicWorldObject* object);

      void AddEventEntry (
        EventTriggeringType& events,
        MapEvent* event);
      void RemoveEventEntry (
        EventTriggeringType& events,
        MapEvent* event);

      bool AddEventEntry (
        const DynamicWorldObject* object,
        MapEvent* event,
        MapEventContext* eventContext);
      bool RemoveEventEntry (
        const DynamicWorldObject* object,
        MapEvent* event,
        MapEventContext* eventContext);

      void UpdateObject (const Time& dt, DynamicWorldObject& object);

      void UpdateObjectOut (const Time& dt, const DynamicWorldObject& object);
      void UpdateObjectIn (const Time& dt, DynamicWorldObject& object);

      bool CallEvent (
        MapEvent::Type type,
        const Time& dt,
        MapEventContext& eventContext);

      ObjectEventsType events_;

      CollidableArea* collidableArea_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTMANAGER_HPP
