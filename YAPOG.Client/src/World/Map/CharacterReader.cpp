#include "World/Map/CharacterReader.hpp"
#include "World/Map/Character.hpp"
#include "YAPOG/System/IO/Xml/XmlReader.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/System/StringHelper.hpp"

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

    yap::String spriteType = reader->ReadString ("spriteType");
    character_.SetSprite (
      yap::ObjectFactory::Instance ().Create<yap::SpriteSet<yap::String>> (
        spriteType,
        *reader,
        spriteType));
  }
} // namespace ycl
