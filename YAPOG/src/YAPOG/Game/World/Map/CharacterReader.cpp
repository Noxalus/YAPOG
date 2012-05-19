#include "YAPOG/Game/World/Map/CharacterReader.hpp"
#include "YAPOG/Game/World/Map/Character.hpp"

namespace yap
{
  CharacterReader::CharacterReader (
    Character& character,
    const String& xmlRootNodeName)
    : DynamicWorldObjectReader (character, xmlRootNodeName)
    , character_ (character)
  {
  }

  CharacterReader::~CharacterReader ()
  {
  }
} // namespace yap
