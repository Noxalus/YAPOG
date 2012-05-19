#include "YAPOG/Graphics/Game/Sprite/SpriteReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/Sprite.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/IO/Xml/XmlHelper.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const String SpriteReader::DEFAULT_XML_TEXTURE_NODE_NAME = "Texture";
  const String SpriteReader::DEFAULT_XML_TEXTURE_ID_NODE_NAME = "id";

  SpriteReader::SpriteReader (
    Sprite& sprite, 
    const String& xmlRootNodeName)
    : BaseSpriteReader (sprite, xmlRootNodeName)
    , sprite_ (sprite)
  {
  }

  SpriteReader::~SpriteReader ()
  {
  }

  void SpriteReader::Visit (XmlReader& visitable)
  {
    auto reader = visitable.ChangeRoot (xmlRootNodeName_);
    reader = reader->ChangeRoot (DEFAULT_XML_TEXTURE_NODE_NAME);

    sprite_.SetTexture (
      ObjectFactory::Instance ().Create<Texture> (
        "Texture",
        reader->ReadID (
        XmlHelper::GetAttrNodeName (DEFAULT_XML_TEXTURE_ID_NODE_NAME))));
  }
} // namespace yap
