#include "YAPOG/Game/World/Map/DynamicWorldObjectReader.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  DynamicWorldObjectReader::DynamicWorldObjectReader (
    DynamicWorldObject& dynamicWorldObject,
    const String& xmlRootNodeName)
    : WorldObjectReader (dynamicWorldObject, xmlRootNodeName)
    , dynamicWorldObject_ (dynamicWorldObject)
  {
  }

  DynamicWorldObjectReader::~DynamicWorldObjectReader ()
  {
  }
} // namespace yap
