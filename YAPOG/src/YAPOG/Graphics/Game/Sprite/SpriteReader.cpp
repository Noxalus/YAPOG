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

  SpriteReader::SpriteReader (Sprite& sprite, const String& xmlRootNodeName)
    : BaseSpriteReader (sprite, xmlRootNodeName)
    , sprite_ (sprite)
  {
  }

  SpriteReader::~SpriteReader ()
  {
  }

  void SpriteReader::Visit (XmlReader& visitable)
  {
    // <Sprite>

    if (!visitable.TryChangeRoot (xmlRootNodeName_))
      YAPOG_THROW("Failed to read `" + xmlRootNodeName_ + "' node.");

    // <Texture id="{id}"/>

    visitable.DownChangeRoot (DEFAULT_XML_TEXTURE_NODE_NAME);

    sprite_.SetTexture (
      ObjectFactory::Instance ().Create<Texture> (
        "Texture",
        visitable.ReadID (
          XmlHelper::GetAttrNodeName (DEFAULT_XML_TEXTURE_ID_NODE_NAME))));

    visitable.UpChangeRoot ();

    // </Sprite>
  }
} // namespace yap
