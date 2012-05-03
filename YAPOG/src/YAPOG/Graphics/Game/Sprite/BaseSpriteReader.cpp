#include "YAPOG/Graphics/Game/Sprite/BaseSpriteReader.hpp"

namespace yap
{
  BaseSpriteReader::BaseSpriteReader (
    BaseSprite& baseSprite,
    const String& xmlRootNodeName)
    : xmlRootNodeName_ (xmlRootNodeName)
    , baseSprite_ (baseSprite)
  {
  }

  BaseSpriteReader::~BaseSpriteReader ()
  {
  }

  void BaseSpriteReader::Visit (XmlReader& visitable)
  {
  }
} // namespace yap
