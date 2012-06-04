#include "YAPOG/Game/World/Map/MapEventContext.hpp"

namespace yap
{
  MapEventContext::MapEventContext (
    const ICollidable& triggerCollidable,
    const MapEventInfo& mapEventInfo)
    : triggerCollidable_ (triggerCollidable)
    , mapEventInfo_ (mapEventInfo)
  {
  }

  const ICollidable& MapEventContext::GetTriggerCollidable () const
  {
    return triggerCollidable_;
  }

  const MapEventInfo& MapEventContext::GetMapEventInfo () const
  {
    return mapEventInfo_;
  }
} // namespace yap
