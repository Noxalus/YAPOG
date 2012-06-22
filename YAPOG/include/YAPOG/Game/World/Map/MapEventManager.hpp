#ifndef YAPOG_MAPEVENTMANAGER_HPP
# define YAPOG_MAPEVENTMANAGER_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Collection/Set.hpp"
# include "YAPOG/Game/World/Map/MapEventContextTriggerComparator.hpp"
# include "YAPOG/Game/World/Map/MapEvent.hpp"
# include "YAPOG/Collection/Queue.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  class DynamicWorldObject;
  class MapEventContext;
  class BoundingBox;
  class CollidableArea;

  class YAPOG_LIB MapEventManager : public IUpdateable
  {
      DISALLOW_COPY(MapEventManager);

      typedef collection::Map<
        MapEvent*,
        collection::Set<
          MapEventContext*,
          MapEventContextTriggerComparator>> EventTriggeringType;
      /// Map<Trigger Object, Map<Source Event, Set<Event context>>>
      typedef collection::Map<
        const DynamicWorldObject*,
        EventTriggeringType> ObjectEventsType;

    public:

      MapEventManager ();
      ~MapEventManager ();

      void SetCollidableArea (CollidableArea* collidableArea);

      void UpdateObject (DynamicWorldObject& object);
      void RemoveObject (const DynamicWorldObject& object);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      yap::Event<MapEventManager&> OnEventsAborted;

    private:

      bool AddEventEntry (MapEventContext* eventContext);
      bool RemoveEventEntry (MapEventContext* eventContext);

      void UpdateObjectOut (const DynamicWorldObject& object);
      void UpdateObjectIn (DynamicWorldObject& object);

      void AddLeaveEvent (MapEventContext* event);
      void AddEnterEvent (MapEventContext* event);

      void CallEvents (const Time& dt);

      bool CallEvent (
        MapEventActionType type,
        const Time& dt,
        MapEventContext& eventContext);

      void AbortEvents ();

      ObjectEventsType events_;
      collection::Queue<MapEventContext*> leaveEvents_;
      collection::Queue<MapEventContext*> enterEvents_;

      collection::Queue<const DynamicWorldObject*> objectsToRemove_;

      CollidableArea* collidableArea_;

      bool abortEvents_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTMANAGER_HPP
