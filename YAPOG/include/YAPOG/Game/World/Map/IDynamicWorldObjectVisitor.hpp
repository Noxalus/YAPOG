#ifndef YAPOG_IDYNAMICWORLDOBJECTVISITOR_HPP
# define YAPOG_IDYNAMICWORLDOBJECTVISITOR_HPP

namespace yap
{
  struct INPC;
  struct IPlayer;

  class BattleSpawnerArea;
  class Character;
  class DestructibleObject;
  class DynamicWorldObject;
  class Teleporter;

  struct IDynamicWorldObjectVisitor
  {
      virtual ~IDynamicWorldObjectVisitor () { }

      virtual void VisitDynamicWorldObject (DynamicWorldObject& visitable) = 0;
      virtual void VisitCharacter (Character& visitable) = 0;
      virtual void VisitPlayer (IPlayer& visitable) = 0;
      virtual void VisitNPC (INPC& visitable) = 0;
      virtual void VisitTeleporter (Teleporter& visitable) = 0;
      virtual void VisitDestructibleObject (DestructibleObject& visitable) = 0;
      virtual void VisitBattleSpawnerArea (BattleSpawnerArea& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDYNAMICWORLDOBJECTVISITOR_HPP
