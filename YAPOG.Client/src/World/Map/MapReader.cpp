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

MapReader::MapReader (Map& map)
  : yap::MapReader (map)
  , map_ (map)
{
}

MapReader::~MapReader ()
{
}

void MapReader::Visit (yap::XmlReader& visitable)
{
  yap::MapReader::Visit (visitable);

  if (!visitable.TryChangeRoot (DEFAULT_XML_ROOT_NODE_NAME))
    throw yap::Exception (
    "Failed to read `" + DEFAULT_XML_ROOT_NODE_NAME + "' node.");

  visitable.DownChangeRoot ("ground");

  /*
  yap::XmlReaderCollection tileSetReaders;
  for (auto& tileSetReader : visitable.ReadNodes ("tileLayer", tileSetReaders))
  {
  yap::uint height = tileSetReader->ReadUInt ("height");
  yap::RandomTileLayoutHandler* tileLayoutHandler =
  new yap::RandomTileLayoutHandler ();

  yap::XmlReaderCollection tileReaders;
  for (auto& tileReader : tileSetReader->ReadNodes ("Tile", tileReaders))
  {
  yap::Tile* tile = yap::ObjectFactory::Instance ().Create<yap::Tile> (
  "Tile",
  tileReader->ReadID (yap::XmlHelper::GetAttrNodeName ("id")));

  tileLayoutHandler->AddTile (tile);
  }

  map_.AddTileLayer (height, tileLayoutHandler);
  }
  */

  visitable.UpChangeRoot ();
}
