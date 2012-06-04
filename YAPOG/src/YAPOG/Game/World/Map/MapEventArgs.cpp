#include "YAPOG/Game/World/Map/MapEventArgs.hpp"

namespace yap
{
  MapEventArgs::MapEventArgs (
    const ICollidable& sourceCollidable,
    const ICollidable& triggerCollidable,
    const DynamicWorldObject& source,
    const DynamicWorldObject& trigger,
    const MapEventInfo& context)
    : sourceCollidable_ (sourceCollidable)
    , triggerCollidable_ (triggerCollidable)
    , source_ (source)
    , trigger_ (trigger)
    , context_ (context)
  {
  }
} // namespace yap
