#include "YAPOG/Game/World/Map/MapElement.hpp"

namespace yap
{
  MapElement::MapElement (const ID& id)
    : StaticWorldObject (id)
  {
  }

  MapElement::~MapElement ()
  {
  }

  MapElement::MapElement (const MapElement& copy)
    : StaticWorldObject (copy)
  {
  }
} // namespace yap
