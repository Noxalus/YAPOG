#include "YAPOG/Graphics/Game/Sprite/SpriteReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"

namespace yap
{
  const String SpriteReader::DEFAULT_XML_ROOT_NODE_NAME = "Sprite";

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

  }
} // namespace yap
