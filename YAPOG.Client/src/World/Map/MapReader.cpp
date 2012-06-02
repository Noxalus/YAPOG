#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/System/IntTypes.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "World/Map/MapElement.hpp"

namespace ycl
{
  MapReader::MapReader (Map& map, const yap::String& xmlRootNodeName)
    : yap::MapReader (map, xmlRootNodeName)
    , map_ (map)
  {
  }

  MapReader::~MapReader ()
  {
  }

  void MapReader::Visit (yap::XmlReader& visitable)
  {
    yap::MapReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    auto groundReader = reader->ChangeRoot ("ground");

    yap::XmlReaderCollection tileSetReaders;
    groundReader->ReadNodes ("tileLayer", tileSetReaders);
    for (auto& tileSetReader : tileSetReaders)
    {
      yap::uint height = tileSetReader->ReadUInt ("height");
      yap::String layoutHandlerType = tileSetReader->ReadString (
        "layoutHandlerType");

      yap::TileLayoutHandler* tileLayoutHandler =
        yap::ObjectFactory::Instance ().Create<yap::TileLayoutHandler> (
          layoutHandlerType,
          *tileSetReader,
          "tileLayer");

      map_.AddTileLayer (height, tileLayoutHandler);
    }
  }

  void MapReader::ReadMapElement (yap::XmlReader& reader)
  {
    yap::ID mapElementID = reader.ReadID (
      yap::XmlHelper::GetAttrNodeName ("id"));

    MapElement* mapElement =
      yap::ObjectFactory::Instance ().Create<MapElement> (
        "MapElement",
        mapElementID);

    yap::Vector2 mapElementPosition = reader.ReadVector2 (
      "position");

    mapElement->SetPosition (mapElementPosition);

    map_.AddMapElement (mapElement);
  }
} // namespace ycl
