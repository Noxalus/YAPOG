#include "World/Map/CharacterReader.hpp"
#include "World/Map/Character.hpp"

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
