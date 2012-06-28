#include "YAPOG/Game/World/Map/MapAreaReader.hpp"
#include "YAPOG/Game/World/Map/MapArea.hpp"

namespace yap
{
  MapAreaReader::MapAreaReader (
    MapArea& mapArea,
    const String& xmlRootNodeName)
    : DynamicWorldObjectReader (mapArea, xmlRootNodeName)
    , mapArea_ (mapArea)
  {
  }

  MapAreaReader::~MapAreaReader ()
  {
  }
} // namespace yap
