#include "YAPOG/Game/World/Map/StaticWorldObjectReader.hpp"
#include "YAPOG/Game/World/Map/StaticWorldObject.hpp"

namespace yap
{
  StaticWorldObjectReader::StaticWorldObjectReader (
    StaticWorldObject& staticWorldObject,
    const String& xmlRootNodeName)
    : WorldObjectReader (staticWorldObject, xmlRootNodeName)
    , staticWorldObject_ (staticWorldObject)
  {
  }

  StaticWorldObjectReader::~StaticWorldObjectReader ()
  {
  }
} // namespace yap
