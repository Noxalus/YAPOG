#include "YAPOG/Game/World/Map/MapElement.hpp"
#include "YAPOG/Game/World/Map/IStaticWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IStaticWorldObjectConstVisitor.hpp"

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

  void MapElement::Accept (IStaticWorldObjectVisitor& visitor)
  {
    visitor.Visit (*this);
  }

  void MapElement::Accept (IStaticWorldObjectConstVisitor& visitor) const
  {
    visitor.Visit (*this);
  }
} // namespace yap
