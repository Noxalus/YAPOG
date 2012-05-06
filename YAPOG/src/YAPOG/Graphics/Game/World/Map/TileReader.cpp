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
  const String TileReader::DEFAULT_XML_SPRITE_TYPE_NODE_NAME = "spriteType";

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
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    tile_.SetID (
      reader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_ID_NODE_NAME)));

    String spriteType = reader->ReadString (
      DEFAULT_XML_SPRITE_TYPE_NODE_NAME);

    tile_.SetSprite (
      ObjectFactory::Instance ().Create<ISprite> (
        spriteType,
        *reader,
        spriteType));
  }
} // namespace yap
