#include "YAPOG/Game/World/Map/MapEventArgs.hpp"

namespace yap
{
  const bool MapEventArgs::DEFAULT_ABORT_EVENTS_STATE = false;

  MapEventArgs::MapEventArgs (
    const Time& dt,
    DynamicWorldObject& trigger,
    const ICollidable& triggerCollidable,
    MapEventInfo& mapContext)
    : dt_ (dt)
    , trigger_ (trigger)
    , triggerCollidable_ (triggerCollidable)
    , mapContext_ (mapContext)
    , abortEvents_ (DEFAULT_ABORT_EVENTS_STATE)
  {
  }

  const Time& MapEventArgs::GetDt () const
  {
    return dt_;
  }

  DynamicWorldObject& MapEventArgs::GetTrigger ()
  {
    return trigger_;
  }

  const ICollidable& MapEventArgs::GetTriggerCollidable () const
  {
    return triggerCollidable_;
  }

  MapEventInfo& MapEventArgs::GetMapContext ()
  {
    return mapContext_;
  }

  void MapEventArgs::AbortEvents (bool abortEvents)
  {
    abortEvents_ = abortEvents;
  }

  bool MapEventArgs::AbortEvents () const
  {
    return abortEvents_;
  }
} // namespace yap
