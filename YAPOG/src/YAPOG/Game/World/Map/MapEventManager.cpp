#include "YAPOG/Game/World/Map/MapEventManager.hpp"
#include "YAPOG/Game/World/Map/MapEventQueue.hpp"
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
    const DynamicWorldObject& object)
  {
    UpdateObjectOut (dt, object);
    UpdateObjectIn (dt, object);
  }

  void MapEventManager::UpdateObjectOut (
    const Time& dt,
    const DynamicWorldObject& object)
  {
    /// @warning Temporary pseudo-code.

    /// @todo Create it on calling method and pass it by  arg.

/*
    collection::Map<
      BoundingBox*,
      collection::Set<MapEventArgs*>>& objectEvents = events_[&object];

    for (auto& objectEvent : objectEvents)
    {
      BoundingBox& sourceBoundingBox = objectEvent.first;

      for (MapEventArgs* objectEventArgs : objectEvent.second)
      {
        if (objectEvent.first.CollidesWith (objectEventArgs->triggerBB))
          continue;

        /// @todo Remove event.
      }
      }*/
  }

  void MapEventManager::UpdateObjectIn (
    const Time& dt,
    const DynamicWorldObject& object)
  {
    MapEventQueue events;

    collidableArea_->GetEventsCollidingWithObject (object, events);
  }
} // namespace yap
