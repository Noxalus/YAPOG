#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Graphics/Game/Sprite/ISprite.hpp"

#include "World/Map/DestructibleObjectReader.hpp"
#include "World/Map/DestructibleObject.hpp"

namespace ycl
{
  const yap::String
  DestructibleObjectReader::DEFAULT_XML_SPRITE_TYPE_NODE_NAME = "spriteType";

  DestructibleObjectReader::DestructibleObjectReader (
    DestructibleObject& destructibleObject,
    const yap::String& xmlRootNodeName)
    : yap::DestructibleObjectReader (destructibleObject, xmlRootNodeName)
    , destructibleObject_ (destructibleObject)
  {
  }

  DestructibleObjectReader::~DestructibleObjectReader ()
  {
  }

  void DestructibleObjectReader::Visit (yap::XmlReader& visitable)
  {
    yap::DestructibleObjectReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);

    yap::String spriteType = reader->ReadString (
      DEFAULT_XML_SPRITE_TYPE_NODE_NAME);
    destructibleObject_.SetSprite (
      yap::ObjectFactory::Instance ().Create<yap::ISprite> (
        spriteType,
        *reader,
        spriteType));
  }
} // namespace ycl
