#include "YAPOG/Game/World/Map/MapReader.hpp"
#include "YAPOG/Game/World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/System/Error/Exception.hpp"

namespace yap
{
  const String MapReader::DEFAULT_XML_ROOT_NODE_NAME = "Map";
  const String MapReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String MapReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String MapReader::DEFAULT_XML_WIDTH_NODE_NAME = "width";
  const String MapReader::DEFAULT_XML_HEIGHT_NODE_NAME = "height";


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
    // <Map id="{id}">

    if (!visitable.TryChangeRoot (DEFAULT_XML_ROOT_NODE_NAME))
      throw Exception (
        "Failed to read `" + DEFAULT_XML_ROOT_NODE_NAME + "' node.");

    map_.SetID (
      visitable.ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    // <name>

    map_.SetName (visitable.ReadString (DEFAULT_XML_NAME_NODE_NAME));

    // </name>

    // <width/height>

    map_.SetSize (
      visitable.ReadUInt (DEFAULT_XML_WIDTH_NODE_NAME),
      visitable.ReadUInt (DEFAULT_XML_HEIGHT_NODE_NAME));

    // </width/height>

    visitable.UpChangeRoot ();

    // </Map>
  }
} // namespace yap
