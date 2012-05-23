#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "World/Map/MapElementReader.hpp"
#include "World/Map/MapElement.hpp"

namespace ycl
{
  const yap::String MapElementReader::DEFAULT_XML_SPRITE_TYPE_NODE_NAME =
    "spriteType";

  MapElementReader::MapElementReader (
    MapElement& mapElement,
    const yap::String& xmlRootNodeName)
    : yap::MapElementReader (mapElement, xmlRootNodeName)
    , mapElement_ (mapElement)
  {
  }

  MapElementReader::~MapElementReader ()
  {
  }

  void MapElementReader::Visit (yap::XmlReader& visitable)
  {
    yap::MapElementReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    yap::String spriteType = reader->ReadString (
      DEFAULT_XML_SPRITE_TYPE_NODE_NAME);
    mapElement_.SetSprite (
      yap::ObjectFactory::Instance ().Create<yap::ISprite> (
        spriteType,
        *reader,
        spriteType));
  }
} // namespace ycl
