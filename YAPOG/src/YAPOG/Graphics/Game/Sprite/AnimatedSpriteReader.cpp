#include "YAPOG/Graphics/Game/Sprite/AnimatedSpriteReader.hpp"
#include "YAPOG/Graphics/Game/Sprite/AnimatedSprite.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  AnimatedSpriteReader::AnimatedSpriteReader (
    AnimatedSprite& animatedSprite,
    const String& xmlRootNodeName)
    : BaseSpriteReader (animatedSprite, xmlRootNodeName)
    , animatedSprite_ (animatedSprite)
  {
  }

  AnimatedSpriteReader::~AnimatedSpriteReader ()
  {
  }

  void AnimatedSpriteReader::Visit (XmlReader& visitable)
  {
    if (!visitable.TryChangeRoot (xmlRootNodeName_))
      YAPOG_THROW("Failed to read `" + xmlRootNodeName_ + "' node.");

    XmlReaderCollection spriteReaders;
    visitable.ReadNodes ("sprite", spriteReaders);
    for (auto& spriteReader : spriteReaders)
    {
      String spriteType = spriteReader->ReadString ("spriteType");

      animatedSprite_.AddFrame (
        ObjectFactory::Instance ().Create<ISprite> (
          spriteType,
          *spriteReader,
          spriteType));
    }

    visitable.UpChangeRoot ();
  }
} // namespace yap
