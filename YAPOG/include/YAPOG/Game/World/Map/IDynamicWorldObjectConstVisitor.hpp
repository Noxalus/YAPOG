#ifndef YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP

namespace yap
{
  struct INPC;
  struct IPlayer;

  class BattleSpawnerArea;
  class DestructibleObject;
  class Character;
  class DynamicWorldObject;
  class Teleporter;

  struct IDynamicWorldObjectConstVisitor
  {
      virtual ~IDynamicWorldObjectConstVisitor () { }

      virtual void VisitDynamicWorldObject (
        const DynamicWorldObject& visitable) = 0;

      virtual void VisitCharacter (const Character& visitable) = 0;
      virtual void VisitPlayer (const IPlayer& visitable) = 0;
      virtual void VisitNPC (const INPC& visitable) = 0;
      virtual void VisitTeleporter (const Teleporter& visitable) = 0;
      virtual void VisitDestructibleObject (
        const DestructibleObject& visitable) = 0;
      virtual void VisitBattleSpawnerArea (
        const BattleSpawnerArea& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP
