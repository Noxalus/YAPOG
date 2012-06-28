#include "YAPOG/Game/World/Map/MapArea.hpp"

namespace yap
{
  MapArea::MapArea (const ID& id)
    : DynamicWorldObject (id)
    , area_ ()
  {
  }

  MapArea::~MapArea ()
  {
  }

  MapArea::MapArea (const MapArea& copy)
    : DynamicWorldObject (copy)
    , area_ (copy.area_)
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
