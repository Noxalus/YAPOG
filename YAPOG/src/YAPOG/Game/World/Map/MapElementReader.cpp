#include "YAPOG/Game/World/Map/MapElementReader.hpp"
#include "YAPOG/Game/World/Map/MapElement.hpp"

namespace yap
{
  MapElementReader::MapElementReader (
    MapElement& mapElement,
    const yap::String& xmlRootNodeName)
    : StaticWorldObjectReader (mapElement, xmlRootNodeName)
    , mapElement_ (mapElement)
  {
  }

  MapElementReader::~MapElementReader ()
  {
  }
} // namespace yap
