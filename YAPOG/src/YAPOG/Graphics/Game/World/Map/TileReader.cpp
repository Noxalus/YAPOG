#include "YAPOG/Graphics/Game/World/Map/TileReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Graphics/Game/World/Map/Tile.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  const String TileReader::DEFAULT_XML_ROOT_NODE_NAME = "Tile";
  const String TileReader::DEFAULT_XML_ID_NODE_NAME = "id";

  TileReader::TileReader (Tile& tile)
    : tile_ (tile)
    , xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  TileReader::TileReader (Tile& tile, const String& xmlRootNodeName)
    : tile_ (tile)
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  TileReader::~TileReader ()
  {
  }

  void TileReader::Visit (XmlReader& visitable)
  {
    // <Tile>

    if (!visitable.TryChangeRoot (DEFAULT_XML_ROOT_NODE_NAME))
      throw Exception (
        "Failed to read `" + DEFAULT_XML_ROOT_NODE_NAME + "' node.");

    tile_.SetID (
      visitable.ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    // <{SpriteType}>

    const String& spriteType = visitable.GetNode (1);
    tile_.SetSprite (
      ObjectFactory::Instance ().Create<ISprite> (
        spriteType,
        visitable,
        spriteType));

    // </{SpriteType}>

    visitable.UpChangeRoot ();

    // </Tile>
  }
} // namespace yap
