#include "YAPOG/Game/World/Map/BattleSpawnerAreaReader.hpp"
#include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"

namespace yap
{
  BattleSpawnerAreaReader::BattleSpawnerAreaReader (
    BattleSpawnerArea& battleSpawnerArea,
    const String& xmlRootNodeName)
    : MapAreaReader (battleSpawnerArea, xmlRootNodeName)
    , battleSpawnerArea_ (battleSpawnerArea)
  {
  }

  BattleSpawnerAreaReader::~BattleSpawnerAreaReader ()
  {
  }
} // namespace yap
