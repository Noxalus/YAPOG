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

  MapElement* MapElement::Clone () const
  {
    return new MapElement (*this);
  }

  void MapElement::Accept (IStaticWorldObjectVisitor& visitor)
  {
    StaticWorldObject::Accept (visitor);

    visitor.VisitMapElement (*this);
  }

  void MapElement::Accept (IStaticWorldObjectConstVisitor& visitor) const
  {
    StaticWorldObject::Accept (visitor);

    visitor.VisitMapElement (*this);
  }
} // namespace yap
