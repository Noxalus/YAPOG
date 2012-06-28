#include "YAPOG/Game/World/Map/OpenBattleSpawnerAreaReader.hpp"
#include "YAPOG/Game/World/Map/OpenBattleSpawnerArea.hpp"

namespace yap
{
  OpenBattleSpawnerAreaReader::OpenBattleSpawnerAreaReader (
    OpenBattleSpawnerArea& openBattleSpawnerArea,
    const String& xmlRootNodeName)
    : BattleSpawnerAreaReader (openBattleSpawnerArea, xmlRootNodeName)
    , openBattleSpawnerArea_ (openBattleSpawnerArea)
  {
  }

  OpenBattleSpawnerAreaReader::~OpenBattleSpawnerAreaReader ()
  {
  }
} // namespace yap
