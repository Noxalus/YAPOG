#ifndef YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  class YAPOG_LIB BaseDynamicWorldObjectConstVisitor
    : public IDynamicWorldObjectConstVisitor
  {
      DISALLOW_COPY(BaseDynamicWorldObjectConstVisitor);

    public:

      virtual ~BaseDynamicWorldObjectConstVisitor ();

      virtual void VisitDynamicWorldObject (
        const DynamicWorldObject& visitable);
      virtual void VisitCharacter (const Character& visitable);
      virtual void VisitPlayer (const IPlayer& visitable);
      virtual void VisitTeleporter (const Teleporter& visitable);
      virtual void VisitDestructibleObject (
        const DestructibleObject& visitable);
      virtual void VisitBattleSpawnerArea (const BattleSpawnerArea& visitable);

    protected:

      BaseDynamicWorldObjectConstVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP
