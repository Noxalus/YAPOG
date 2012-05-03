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

    if (!visitable.TryChangeRoot (xmlRootNodeName_))
      YAPOG_THROW("Failed to read `" + xmlRootNodeName_ + "' node.");

    yap::String spriteType = visitable.ReadString ("spriteType");
    character_.SetSprite (
      yap::ObjectFactory::Instance ().Create<yap::SpriteSet<yap::String>> (
        spriteType,
        visitable,
        spriteType));
  }
} // namespace ycl
