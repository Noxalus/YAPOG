#include "World/Map/MapReader.hpp"
#include "World/Map/Map.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/System/IntTypes.hpp"
#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandler.hpp"

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

  if (!visitable.TryChangeRoot (xmlRootNodeName_))
    throw yap::Exception (
      "Failed to read `" + xmlRootNodeName_ + "' node.");

  visitable.DownChangeRoot ("ground");

  yap::XmlReaderCollection tileSetReaders;
  visitable.ReadNodes ("tileLayer", tileSetReaders);
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

  visitable.UpChangeRoot ();
}
