#include "World/Map/CharacterReader.hpp"
#include "World/Map/Character.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/IO/Xml/XmlReaderCollection.hpp"

namespace ycl
{
  CharacterReader::CharacterReader (
    Character& character,
    const yap::String& xmlRootNodeName)
    : yap::CharacterReader (character, xmlRootNodeName)
    , character_ (character)
  {
  }

  CharacterReader::~CharacterReader ()
  {
  }

  void CharacterReader::Visit (yap::XmlReader& visitable)
  {
    yap::CharacterReader::Visit (visitable);

    auto reader = visitable.ChangeRoot (xmlRootNodeName_);
    auto stringSpriteSetReader = reader->ChangeRoot ("StringSpriteSet");

    yap::XmlReaderCollection directionSpriteReaders;
    stringSpriteSetReader->ReadNodes ("sprite", directionSpriteReaders);
    for (auto& directionSpriteReader : directionSpriteReaders)
    {
      yap::String state = directionSpriteReader->ReadString ("key");
      yap::String spriteType = directionSpriteReader->ReadString (
        "spriteType");

      character_.AddSprite (
        state,
        yap::ObjectFactory::Instance ().Create<
          yap::SpriteSet<yap::Direction>> (
            spriteType,
            *directionSpriteReader,
            spriteType));
    }
  }
} // namespace ycl
