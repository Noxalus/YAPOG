#include "YAPOG/Game/World/Map/MapEventArgs.hpp"

namespace yap
{
  MapEventArgs::MapEventArgs (
    const Time& dt,
    DynamicWorldObject& trigger,
    const ICollidable& triggerCollidable,
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

  const ICollidable& MapEventArgs::GetTriggerCollidable () const
  {
    return triggerCollidable_;
  }

  MapEventInfo& MapEventArgs::GetMapContext ()
  {
    return mapContext_;
  }
} // namespace yap
