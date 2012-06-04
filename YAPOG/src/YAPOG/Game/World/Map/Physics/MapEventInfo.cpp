#include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"

namespace yap
{
  MapEventInfo::MapEventInfo (
    const ICollidable& sourceCollidable,
    const MapEvent& event,
    const DynamicWorldObject& parent)
    : sourceCollidable_ (sourceCollidable)
    , event_ (event)
    , parent_ (parent)
  {
  }

  const ICollidable& MapEventInfo::GetSourceCollidable () const
  {
    return sourceCollidable_;
  }

  const MapEvent& MapEventInfo::GetEvent () const
  {
    return event_;
  }

  const DynamicWorldObject& MapEventInfo::GetParent () const
  {
    return parent_;
  }
} // namespace yap
