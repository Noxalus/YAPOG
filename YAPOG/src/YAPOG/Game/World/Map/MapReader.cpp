#include "YAPOG/Game/World/Map/MapReader.hpp"
#include "YAPOG/Game/World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/World/Map/MapElement.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"

/// @todo Remove when integrating CollidableArea.
#include "YAPOG/Game/World/Map/Physics/GridCollidableArea.hpp"

namespace yap
{
  const String MapReader::DEFAULT_XML_ID_NODE_NAME = "id";
  const String MapReader::DEFAULT_XML_NAME_NODE_NAME = "name";
  const String MapReader::DEFAULT_XML_WIDTH_NODE_NAME = "width";
  const String MapReader::DEFAULT_XML_HEIGHT_NODE_NAME = "height";

  MapReader::MapReader (Map& map, const String& xmlRootNodeName)
    : BaseReaderVisitor ()
    , xmlRootNodeName_ (xmlRootNodeName)
    , map_ (map)
  {
  }

  MapReader::~MapReader ()
  {
  }

  void MapReader::Visit (XmlReader& visitable)
  {
    BaseReaderVisitor::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    map_.SetID (
      reader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    map_.SetName (reader->ReadString (DEFAULT_XML_NAME_NODE_NAME));

    /// @todo Integrate CollidableArea in xml loading (remove inclusion).
    GridCollidableArea* gridCollidableArea = new GridCollidableArea ();
    gridCollidableArea->SetSegmentCount (10, 10);
    map_.SetCollidableArea (gridCollidableArea);

    map_.SetSize (
      reader->ReadUInt (DEFAULT_XML_WIDTH_NODE_NAME),
      reader->ReadUInt (DEFAULT_XML_HEIGHT_NODE_NAME));

    auto staticObjectsReader = reader->ChangeRoot ("staticObjects");

    XmlReaderCollection mapElementReaders;
    staticObjectsReader->ReadNodes ("MapElement", mapElementReaders);
    for (auto& mapElementReader : mapElementReaders)
      ReadMapElement (*mapElementReader);
  }

  void MapReader::ReadMapElement (XmlReader& reader)
  {
    ID mapElementID = reader.ReadID (
      XmlHelper::GetAttrNodeName ("id"));

    MapElement* mapElement =
      ObjectFactory::Instance ().Create<MapElement> (
        "MapElement",
        mapElementID);

    Vector2 mapElementPosition = reader.ReadVector2 (
      "position");

    mapElement->SetPosition (mapElementPosition);

    map_.AddStaticObject (mapElement);
  }
} // namespace yap
