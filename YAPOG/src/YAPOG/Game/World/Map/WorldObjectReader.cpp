#include "YAPOG/Game/World/Map/WorldObjectReader.hpp"
#include "YAPOG/Game/World/Map/WorldObject.hpp"

namespace yap
{
  WorldObjectReader::WorldObjectReader (
    WorldObject& worldObject,
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , worldObject_ (worldObject)

  {
  }

  WorldObjectReader::~WorldObjectReader ()
  {
  }

  void WorldObjectReader::Visit (XmlReader& visitable)
  {
  }
} // namespace yap
