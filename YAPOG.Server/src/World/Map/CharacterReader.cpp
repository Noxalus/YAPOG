#include "World/Map/CharacterReader.hpp"
#include "World/Map/Character.hpp"

namespace yse
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
  }
} // namespace yse
