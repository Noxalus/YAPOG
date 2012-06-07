#include "YAPOG/Game/World/Map/MapEventContext.hpp"

namespace yap
{
  MapEventContext::MapEventContext (
    DynamicWorldObject& trigger,
    const ICollidable& triggerCollidable,
    MapEventInfo& mapEventInfo)
    : trigger_ (trigger)
    , triggerCollidable_ (triggerCollidable)
    , mapEventInfo_ (mapEventInfo)
  {
  }

  DynamicWorldObject& MapEventContext::GetTrigger ()
  {
    return trigger_;
  }

  const ICollidable& MapEventContext::GetTriggerCollidable () const
  {
    return triggerCollidable_;
  }

  MapEventInfo& MapEventContext::GetMapEventInfo ()
  {
    return mapEventInfo_;
  }
} // namespace yap
