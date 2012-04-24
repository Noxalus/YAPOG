#include "YAPOG/Graphics/Game/Sprite/SpriteReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"

namespace yap
{
  const String SpriteReader::DEFAULT_XML_ROOT_NODE_NAME = "Sprite";
  const String SpriteReader::DEFAULT_XML_TEXTURE_NODE_NAME = "Texture";
  const String SpriteReader::DEFAULT_XML_TEXTURE_ID_NODE_NAME = "id";

  SpriteReader::SpriteReader (Sprite& sprite)
    : sprite_ (sprite)
    , xmlRootNodeName_ (DEFAULT_XML_ROOT_NODE_NAME)
  {
  }

  SpriteReader::SpriteReader (Sprite& sprite, const String& xmlRootNodeName)
    : sprite_ (sprite)
    , xmlRootNodeName_ (xmlRootNodeName)
  {
  }

  SpriteReader::~SpriteReader ()
  {
  }

  void SpriteReader::Visit (XmlReader& visitable)
  {
    // <Sprite>

//    visitable.ChangeRoot (xmlRootNodeName_);

    // <Texture id="{id}"/>

    visitable.ChangeRoot (DEFAULT_XML_TEXTURE_NODE_NAME);

    sprite_.SetTexture (
      ObjectFactory::Instance ().Create<Texture> (
        "Texture",
        visitable.ReadID (
          XmlHelper::GetAttrNodeName (DEFAULT_XML_TEXTURE_ID_NODE_NAME))));

    // </Sprite>
  }
} // namespace yap
