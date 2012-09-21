#include "YAPOG/Game/World/Map/BaseDynamicWorldObjectVisitor.hpp"

namespace yap
{
  BaseDynamicWorldObjectVisitor::BaseDynamicWorldObjectVisitor ()
  {
  }

  BaseDynamicWorldObjectVisitor::~BaseDynamicWorldObjectVisitor ()
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitDynamicWorldObject (
    DynamicWorldObject& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitCharacter (Character& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitPlayer (IPlayer& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitNPC (INPC& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitTeleporter (Teleporter& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitDestructibleObject (
    DestructibleObject& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitBattleSpawnerArea (
    BattleSpawnerArea& visitable)
  {
  }
} // namespace yap
