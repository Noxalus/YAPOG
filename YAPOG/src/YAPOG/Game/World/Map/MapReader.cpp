#include "YAPOG/Game/World/Map/MapReader.hpp"
#include "YAPOG/Game/World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/System/Error/Exception.hpp"

/// @todo Remove when integrating CollidableArea.
#include "YAPOG/Game/World/Map/Physics/GridCollidableArea.hpp"

namespace yap
{
  const String MapReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String MapReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String MapReader::DEFAULT_XML_WIDTH_NODE_NAME = "width";
  const String MapReader::DEFAULT_XML_HEIGHT_NODE_NAME = "height";

  MapReader::MapReader (Map& map, const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , map_ (map)
  {
  }

  MapReader::~MapReader ()
  {
  }

  void MapReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    map_.SetID (
      reader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    map_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    /// @todo Integrate CollidableArea in xml loading.
    GridCollidableArea* gridCollidableArea = new GridCollidableArea ();
    gridCollidableArea->SetSegmentCount (10, 10);
    map_.SetCollidableArea (gridCollidableArea);

    map_.SetSize (
      reader->ReadUInt (DEFAULT_XML_WIDTH_NODE_NAME),
      reader->ReadUInt (DEFAULT_XML_HEIGHT_NODE_NAME));
  }
} // namespace yap
