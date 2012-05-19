#include "YAPOG/Graphics/Game/World/Map/TileLayoutHandlerReader.hpp"

namespace yap
{
  const String TileLayoutHandlerReader::DEFAULT_XML_ROOT_NODE_NAME =
    "tileLayer";
  const String TileLayoutHandlerReader::DEFAULT_XML_TYPE_NODE_NAME =
    "layoutHandlertype";
  const String TileLayoutHandlerReader::DEFAULT_XML_TILE_NODE_NAME = "Tile";

  TileLayoutHandlerReader::TileLayoutHandlerReader ()
    : xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  TileLayoutHandlerReader::TileLayoutHandlerReader (
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  TileLayoutHandlerReader::~TileLayoutHandlerReader ()
  {
  }
} // namespace yap
