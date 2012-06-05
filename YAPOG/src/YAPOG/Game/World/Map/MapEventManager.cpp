#include "YAPOG/Game/World/Map/MapEventManager.hpp"
#include "YAPOG/Game/World/Map/MapEventContext.hpp"
#include "YAPOG/Game/World/Map/MapEventQueue.hpp"
#include "YAPOG/Game/World/Map/MapEventArgs.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"

namespace yap
{
  MapEventManager::MapEventManager ()
    : events_ ()
  {
  }

  MapEventManager::~MapEventManager ()
  {
  }

  void MapEventManager::SetCollidableArea (CollidableArea* collidableArea)
  {
    collidableArea_ = collidableArea;
  }

  void MapEventManager::Update (const Time& dt)
  {

  }

  void MapEventManager::UpdateObject (
    const Time& dt,
    DynamicWorldObject& object)
  {
    UpdateObjectOut (dt, object);
    UpdateObjectIn (dt, object);
  }

  void MapEventManager::UpdateObjectOut (
    const Time& dt,
    const DynamicWorldObject& object)
  {
    auto objectEvents = events_[&object];

    for (auto& event : objectEvents)
    {
      for (MapEventContext* eventContext : event.second)
      {
        if (event.first->CollidesWith (eventContext->GetTriggerCollidable ()))
        {
          // Event is still triggered.
          continue;
        }

        RemoveEventEntry (&object, event.first, eventContext);

        CallEvent (MapEvent::Type::Out, dt, *eventContext);
      }
    }
  }

  void MapEventManager::UpdateObjectIn (
    const Time& dt,
    DynamicWorldObject& object)
  {
    MapEventQueue events;

    collidableArea_->GetEventsCollidingWithObject (object, events);

    while (!events.IsEmpty ())
    {
      MapEventContext& event = events.GetEvent ();
    }
  }

  void MapEventManager::AddObjectEntry (const DynamicWorldObject* object)
  {
    events_.Add (object, EventTriggeringType ());
  }

  void MapEventManager::AddEventEntry (
    EventTriggeringType& events,
    MapEvent* event)
  {
    events.Add (
      event,
      yap::collection::Set<
        MapEventContext*,
        MapEventContextTriggerComparator> ());
  }

  bool MapEventManager::AddEventEntry (
    const DynamicWorldObject* object,
    MapEvent* event,
    MapEventContext* eventContext)
  {
    auto eventTriggering = events_.TryGetValue (object);

    if (eventTriggering == nullptr)
      AddObjectEntry (object);

    auto eventTriggers = eventTriggering->TryGetValue (event);

    if (eventTriggers == nullptr)
      AddEventEntry (*eventTriggering, event);

    return eventTriggers->Add (eventContext);
  }

  bool MapEventManager::RemoveEventEntry (
    const DynamicWorldObject* object,
    MapEvent* event,
    MapEventContext* eventContext)
  {
    auto eventTriggering = events_.TryGetValue (object);

    if (eventTriggering == nullptr)
      return false;

    auto eventTriggers = eventTriggering->TryGetValue (event);

    if (eventTriggers == nullptr)
      return false;

    if (!eventTriggers->Remove (eventContext))
      return false;

    if (eventTriggers->IsEmpty ())
      eventTriggering->Remove (event);

    if (eventTriggering->IsEmpty ())
      events_.Remove (object);

    return true;
  }

  bool MapEventManager::CallEvent (
    MapEvent::Type type,
    const Time& dt,
    MapEventContext& eventContext)
  {
    MapEvent& event = eventContext.GetMapEventInfo ().GetEvent ();

    if (event.GetType () != type)
      return false;

    MapEventArgs args (
      dt,
      eventContext.GetTrigger (),
      eventContext.GetTriggerCollidable (),
      eventContext.GetMapEventInfo ());

    return event.Call (args);
  }
} // namespace yap
