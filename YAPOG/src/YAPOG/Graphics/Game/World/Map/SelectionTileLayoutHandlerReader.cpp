#include "YAPOG/Graphics/Game/World/Map/SelectionTileLayoutHandlerReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/Graphics/Game/World/Map/SelectionTileLayoutHandler.hpp"

namespace yap
{
  SelectionTileLayoutHandlerReader::SelectionTileLayoutHandlerReader (
    SelectionTileLayoutHandler& selectionTileLayoutHandler,
    const String& xmlRootNodeName)
    : TileLayoutHandlerReader (selectionTileLayoutHandler, xmlRootNodeName)
    , selectionTileLayoutHandler_ (selectionTileLayoutHandler)
  {
  }

  SelectionTileLayoutHandlerReader::~SelectionTileLayoutHandlerReader ()
  {
  }

  void SelectionTileLayoutHandlerReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    uint width = reader->ReadUInt ("width");
    uint height = reader->ReadUInt ("height");

    selectionTileLayoutHandler_.SetSize (width, height);

    auto defaultTileReader = reader->ChangeRoot ("defaultTile");

    Tile* defaultTile = ObjectFactory::Instance ().Create<Tile> (
      TileLayoutHandlerReader::DEFAULT_XML_TILE_NODE_NAME,
      defaultTileReader->ReadID (XmlHelper::GetAttrNodeName ("id")));

    selectionTileLayoutHandler_.SetDefaultTile (defaultTile);

    XmlReaderCollection tileReaders;
    reader->ReadNodes ("Tile", tileReaders);

    for (auto& tileReader : tileReaders)
    {
      Tile* tile = ObjectFactory::Instance ().Create<Tile> (
        TileLayoutHandlerReader::DEFAULT_XML_TILE_NODE_NAME,
        tileReader->ReadID (XmlHelper::GetAttrNodeName ("id")));

      Vector2 tilePosition = tileReader->ReadVector2 ("position");

      selectionTileLayoutHandler_.SetTile (
        tilePosition.x,
        tilePosition.y,
        tile);
    }
  }
} // namespace yap
