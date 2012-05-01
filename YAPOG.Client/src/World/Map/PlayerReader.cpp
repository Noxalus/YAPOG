#include "World/Map/PlayerReader.hpp"
#include "World/Map/Player.hpp"

PlayerReader::PlayerReader (
  Player& player,
  const yap::String& xmlRootNodeName)
  : CharacterReader (player, xmlRootNodeName)
  , player_ (player)
{
}

PlayerReader::~PlayerReader ()
{
}

void PlayerReader::Visit (yap::XmlReader& visitable)
{
  CharacterReader::Visit (visitable);
}
