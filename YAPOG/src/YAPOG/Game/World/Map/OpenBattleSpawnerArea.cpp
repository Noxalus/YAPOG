#include "YAPOG/Game/World/Map/OpenBattleSpawnerArea.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  const String OpenBattleSpawnerArea::OBJECT_FACTORY_TYPE_NAME =
    "OpenBattleSpawnerArea";

  OpenBattleSpawnerArea::OpenBattleSpawnerArea (const ID& id)
    : BattleSpawnerArea (id)
  {
  }

  OpenBattleSpawnerArea::~OpenBattleSpawnerArea ()
  {
  }

  OpenBattleSpawnerArea::OpenBattleSpawnerArea (
    const OpenBattleSpawnerArea& copy)
    : BattleSpawnerArea (copy)
  {
  }

  OpenBattleSpawnerArea* OpenBattleSpawnerArea::Clone () const
  {
    return new OpenBattleSpawnerArea (*this);
  }

  void OpenBattleSpawnerArea::Accept (
    IDynamicWorldObjectVisitor& visitor)
  {
    BattleSpawnerArea::Accept (visitor);

    visitor.VisitBattleSpawnerArea (*this);
  }

  void OpenBattleSpawnerArea::Accept (
    IDynamicWorldObjectConstVisitor& visitor) const
  {
    BattleSpawnerArea::Accept (visitor);

    visitor.VisitBattleSpawnerArea (*this);
  }

  void OpenBattleSpawnerArea::HandleSetArea (const FloatRect& area)
  {
    BattleSpawnerArea::HandleSetArea (area);

    SetBattleSpawningArea (area);
  }

  const String& OpenBattleSpawnerArea::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace yap
