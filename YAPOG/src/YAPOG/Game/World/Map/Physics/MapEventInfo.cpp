#include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"

namespace yap
{
  MapEventInfo::MapEventInfo (
    ICollidable& sourceCollidable,
    MapEvent& event,
    DynamicWorldObject& parent)
    : sourceCollidable_ (sourceCollidable)
    , event_ (event)
    , parent_ (parent)
  {
  }

  ICollidable& MapEventInfo::GetSourceCollidable ()
  {
    return sourceCollidable_;
  }

  MapEvent& MapEventInfo::GetEvent ()
  {
    return event_;
  }

  DynamicWorldObject& MapEventInfo::GetParent ()
  {
    return parent_;
  }
} // namespace yap
