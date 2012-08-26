#include "YAPOG/Game/World/Map/BaseDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  BaseDynamicWorldObjectConstVisitor::BaseDynamicWorldObjectConstVisitor ()
  {
  }

  BaseDynamicWorldObjectConstVisitor::~BaseDynamicWorldObjectConstVisitor ()
  {
  }

  void BaseDynamicWorldObjectConstVisitor::VisitDynamicWorldObject (
    const DynamicWorldObject& visitable)
  {
  }

  void BaseDynamicWorldObjectConstVisitor::VisitCharacter (
    const Character& visitable)
  {
  }

  void BaseDynamicWorldObjectConstVisitor::VisitPlayer (
    const IPlayer& visitable)
  {
  }

  void BaseDynamicWorldObjectConstVisitor::VisitTeleporter (
    const Teleporter& visitable)
  {
  }

  void BaseDynamicWorldObjectConstVisitor::VisitDestructibleObject (
    const DestructibleObject& visitable)
  {
  }

  void BaseDynamicWorldObjectConstVisitor::VisitBattleSpawnerArea (
    const BattleSpawnerArea& visitable)
  {
  }
} // namespace yap
