#include "YAPOG/Game/World/Map/MapEventArgs.hpp"

namespace yap
{
  MapEventArgs::MapEventArgs (
    const Time& dt,
    DynamicWorldObject& trigger,
    ICollidable& triggerCollidable,
    MapEventInfo& mapContext)
    : dt_ (dt)
    , trigger_ (trigger)
    , triggerCollidable_ (triggerCollidable)
    , mapContext_ (mapContext)
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

  ICollidable& MapEventArgs::GetTriggerCollidable ()
  {
    return triggerCollidable_;
  }

  MapEventInfo& MapEventArgs::GetMapContext ()
  {
    return mapContext_;
  }
} // namespace yap
