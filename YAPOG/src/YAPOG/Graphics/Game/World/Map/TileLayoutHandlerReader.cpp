#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandlerReader.hpp"

namespace yap
{
  const String TileLayoutHandlerReader::DEFAULT_XML_TYPE_NODE_NAME =
    "layoutHandlertype";
  const String TileLayoutHandlerReader::DEFAULT_XML_TILE_NODE_NAME = "Tile";

  TileLayoutHandlerReader::TileLayoutHandlerReader (
    TileLayoutHandler& tileLayoutHandler,
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , tileLayoutHandler_ (tileLayoutHandler)
  {
  }

  TileLayoutHandlerReader::~TileLayoutHandlerReader ()
  {
  }
} // namespace yap
