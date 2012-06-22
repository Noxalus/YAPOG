#include "YAPOG/Game/World/Map/MapEventManager.hpp"
#include "YAPOG/Game/World/Map/MapEventContext.hpp"
#include "YAPOG/Game/World/Map/MapEventQueue.hpp"
#include "YAPOG/Game/World/Map/MapEventArgs.hpp"
#include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  MapEventManager::MapEventManager ()
    : events_ ()
    , leaveEvents_ ()
    , enterEvents_ ()
    , objectsToRemove_ ()
    , collidableArea_ (nullptr)
    , abortEvents_ (false)
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
    while (!objectsToRemove_.IsEmpty ())
    {
      const DynamicWorldObject* object = nullptr;
      objectsToRemove_.Dequeue (object);

      events_.Remove (object);

      collection::Queue<MapEventContext*> eventsToRemove;
      for (auto& objectEventsPair : events_)
        for (auto& eventContextPair : objectEventsPair.second)
          for (MapEventContext* eventContext : eventContextPair.second)
            if (&eventContext->GetMapEventInfo ().GetParent () == object)
              eventsToRemove.Enqueue (eventContext);

      while (!eventsToRemove.IsEmpty ())
      {
        MapEventContext* event = eventsToRemove.Dequeue (event);
        RemoveEventEntry (event);
      }
    }

    CallEvents (dt);

    if (abortEvents_)
    {
      abortEvents_ = false;
      Update (dt);
    }
  }

  void MapEventManager::CallEvents (const Time& dt)
  {
    while (!leaveEvents_.IsEmpty ())
    {
      MapEventContext* event = leaveEvents_.Dequeue (event);
      CallEvent (MapEventActionType::Leave, dt, *event);

      if (abortEvents_)
        return;
    }

    while (!enterEvents_.IsEmpty ())
    {
      MapEventContext* event = enterEvents_.Dequeue (event);
      CallEvent (MapEventActionType::Enter, dt, *event);

      if (abortEvents_)
        return;
    }

    for (auto& objectEvents : events_)
    {
      for (auto& eventTriggering : objectEvents.second)
      {
        for (MapEventContext* event : eventTriggering.second)
        {
          CallEvent (MapEventActionType::In, dt, *event);

          if (abortEvents_)
            return;
        }
      }
    }
  }

  void MapEventManager::UpdateObject (DynamicWorldObject& object)
  {
    UpdateObjectOut (object);
    UpdateObjectIn (object);
  }

  void MapEventManager::RemoveObject (const DynamicWorldObject& object)
  {
    objectsToRemove_.Enqueue (&object);
  }

  void MapEventManager::UpdateObjectOut (const DynamicWorldObject& object)
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

        RemoveEventEntry (eventContext);

        AddLeaveEvent (eventContext);
      }
    }
  }

  void MapEventManager::UpdateObjectIn (DynamicWorldObject& object)
  {
    MapEventQueue events;

    object.GetEventsCollidingWith (*collidableArea_, events);

    while (!events.IsEmpty ())
    {
      MapEventContext& event = events.GetEvent ();

      if (!AddEventEntry (&event))
        continue;

      AddEnterEvent (&event);
    }
  }

  bool MapEventManager::AddEventEntry (MapEventContext* eventContext)
  {
    DynamicWorldObject& object = eventContext->GetTrigger ();
    MapEvent& event = eventContext->GetMapEventInfo ().GetEvent ();

    auto eventTriggering = events_.TryGetValue (&object);

    if (eventTriggering == nullptr)
      events_.Add (&object, EventTriggeringType ());

    auto eventTriggers = eventTriggering->TryGetValue (&event);

    if (eventTriggers == nullptr)
    {
      auto triggers = yap::collection::Set<
        MapEventContext*,
        MapEventContextTriggerComparator> ();

      if (!triggers.Add (eventContext))
        return false;

      eventTriggering->Add (
        &event,
        triggers);

      return true;
    }

    return eventTriggers->Add (eventContext);
  }

  bool MapEventManager::RemoveEventEntry (MapEventContext* eventContext)
  {
    DynamicWorldObject& object = eventContext->GetTrigger ();
    MapEvent& event = eventContext->GetMapEventInfo ().GetEvent ();

    auto eventTriggering = events_.TryGetValue (&object);

    if (eventTriggering == nullptr)
      return false;

    auto eventTriggers = eventTriggering->TryGetValue (&event);

    if (eventTriggers == nullptr)
      return false;

    if (!eventTriggers->Remove (eventContext))
      return false;

    if (eventTriggers->IsEmpty ())
      eventTriggering->Remove (&event);

    if (eventTriggering->IsEmpty ())
      events_.Remove (&object);

    return true;
  }

  void MapEventManager::AddLeaveEvent (MapEventContext* event)
  {
    leaveEvents_.Enqueue (event);
  }

  void MapEventManager::AddEnterEvent (MapEventContext* event)
  {
    enterEvents_.Enqueue (event);
  }

  bool MapEventManager::CallEvent (
    MapEventActionType type,
    const Time& dt,
    MapEventContext& eventContext)
  {
    MapEvent& event = eventContext.GetMapEventInfo ().GetEvent ();

    MapEventArgs args (
      dt,
      eventContext.GetTrigger (),
      eventContext.GetTriggerCollidable (),
      eventContext.GetMapEventInfo ());

    bool successful = event.Call (type, args);

    if (args.AbortEvents ())
      AbortEvents ();

    return successful;
  }

  void MapEventManager::AbortEvents ()
  {
    abortEvents_ = true;

    leaveEvents_.Clear ();
    enterEvents_.Clear ();
    events_.Clear ();

    OnEventsAborted (*this, EmptyEventArgs ());
  }
} // namespace yap
