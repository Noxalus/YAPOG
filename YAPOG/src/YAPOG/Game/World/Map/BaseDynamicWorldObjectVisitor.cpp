#include "YAPOG/Game/World/Map/BaseDynamicWorldObjectVisitor.hpp"

namespace yap
{
  BaseDynamicWorldObjectVisitor::BaseDynamicWorldObjectVisitor ()
  {
  }

  BaseDynamicWorldObjectVisitor::~BaseDynamicWorldObjectVisitor ()
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitCharacter (Character& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitPlayer (IPlayer& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitTeleporter (Teleporter& visitable)
  {
  }

  void BaseDynamicWorldObjectVisitor::VisitDestructibleObject (
    DestructibleObject& visitable)
  {
  }
} // namespace yap
