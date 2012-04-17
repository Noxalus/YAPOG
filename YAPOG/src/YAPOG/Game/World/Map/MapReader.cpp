#include "YAPOG/Game/World/Map/MapReader.hpp"
#include "YAPOG/Game/World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  const String MapReader::DEFAULT_XML_ROOT_NODE_NAME = "Map";
  const String MapReader::DEFAULT_XML_NAME_NODE_NAME = "name";

  MapReader::MapReader (Map& map)
    : map_ (map)
    , xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  MapReader::MapReader (Map& map, const String& xmlRootNodeName)
    : map_ (map)
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  MapReader::~MapReader ()
  {
  }

  void MapReader::Visit (XmlReader& visitable)
  {
    visitable.ChangeRoot (xmlRootNodeName_);

    map_.SetName (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));
  }
} // namespace yap
