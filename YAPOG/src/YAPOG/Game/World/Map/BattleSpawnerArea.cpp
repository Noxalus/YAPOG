#include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"

namespace yap
{
  BattleSpawnerArea::BattleSpawnerArea (const ID& id)
    : DynamicWorldObject (id)
    , area_ ()
  {
  }

  BattleSpawnerArea::~BattleSpawnerArea ()
  {
  }

  BattleSpawnerArea::BattleSpawnerArea (const BattleSpawnerArea& copy)
    : DynamicWorldObject (copy)
    , area_ (copy.area_)
  {
  }

  void BattleSpawnerArea::SetArea (const FloatRect& area)
  {
    area_ = area;
  }
} // namespace yap
