#include "YAPOG/Game/World/Map/MapEventContext.hpp"

namespace yap
{
  MapEventContext::MapEventContext (
    DynamicWorldObject& trigger,
    ICollidable& triggerCollidable,
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

  ICollidable& MapEventContext::GetTriggerCollidable ()
  {
    return triggerCollidable_;
  }

  MapEventInfo& MapEventContext::GetMapEventInfo ()
  {
    return mapEventInfo_;
  }
} // namespace yap
