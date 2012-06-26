#ifndef YAPOG_BASEDYNAMICWORLDOBJECTVISITOR_HPP
# define YAPOG_BASEDYNAMICWORLDOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"

namespace yap
{
  class YAPOG_LIB BaseDynamicWorldObjectVisitor
    : public IDynamicWorldObjectVisitor
  {
      DISALLOW_COPY(BaseDynamicWorldObjectVisitor);

    public:

      virtual ~BaseDynamicWorldObjectVisitor ();

      virtual void VisitCharacter (Character& visitable);
      virtual void VisitPlayer (IPlayer& visitable);
      virtual void VisitTeleporter (Teleporter& visitable);
      virtual void VisitDestructibleObject (DestructibleObject& visitable);

    protected:

      BaseDynamicWorldObjectVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEDYNAMICWORLDOBJECTVISITOR_HPP
