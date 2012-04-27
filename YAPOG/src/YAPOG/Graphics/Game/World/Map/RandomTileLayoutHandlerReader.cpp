#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandlerReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp"

namespace yap
{
  RandomTileLayoutHandlerReader::RandomTileLayoutHandlerReader (
    RandomTileLayoutHandler& tileLayoutHandler)
    : TileLayoutHandlerReader ()
    , tileLayoutHandler_ (tileLayoutHandler)
  {
  }

  RandomTileLayoutHandlerReader::RandomTileLayoutHandlerReader (
    RandomTileLayoutHandler& tileLayoutHandler,
    const String& xmlRootNodeName)
    : TileLayoutHandlerReader (xmlRootNodeName)
    , tileLayoutHandler_ (tileLayoutHandler)
  {
  }

  RandomTileLayoutHandlerReader::~RandomTileLayoutHandlerReader ()
  {
  }

  void RandomTileLayoutHandlerReader::Visit (XmlReader& visitable)
  {
    XmlReaderCollection tileReaders;
    visitable.ReadNodes ("Tile", tileReaders);

    for (auto& tileReader : tileReaders)
    {
      Tile* tile = ObjectFactory::Instance ().Create<Tile> (
        TileLayoutHandlerReader::DEFAULT_XML_TILE_NODE_NAME,
        tileReader->ReadID (XmlHelper::GetAttrNodeName ("id")));

      tileLayoutHandler_.AddTile (tile);
    }
  }
} // namespace yap
