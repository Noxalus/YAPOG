#include "YAPOG/Game/World/Map/MapArea.hpp"

namespace yap
{
  const bool MapArea::DEFAULT_TRIGGERS_BATTLE = true;

  MapArea::MapArea (const ID& id)
    : DynamicWorldObject (id)
    , area_ ()
    , triggersBattle_ (DEFAULT_TRIGGERS_BATTLE)
  {
  }

  MapArea::~MapArea ()
  {
  }

  MapArea::MapArea (const MapArea& copy)
    : DynamicWorldObject (copy)
    , area_ (copy.area_)
    , triggersBattle_ (copy.triggersBattle_)
  {
  }

  void MapArea::SetArea (const FloatRect& area)
  {
    area_ = area;

    HandleSetArea (area);
  }

  void MapArea::HandleSetArea (const FloatRect& area)
  {
  }
} // namespace yap
