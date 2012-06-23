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
    RandomTileLayoutHandler& randomTileLayoutHandler,
    const String& xmlRootNodeName)
    : TileLayoutHandlerReader (randomTileLayoutHandler, xmlRootNodeName)
    , randomTileLayoutHandler_ (randomTileLayoutHandler)
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

      randomTileLayoutHandler_.AddTile (tile);
    }
  }
} // namespace yap
