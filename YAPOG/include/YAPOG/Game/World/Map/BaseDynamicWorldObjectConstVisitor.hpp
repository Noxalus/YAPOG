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

      virtual void VisitCharacter (const Character& visitable);
      virtual void VisitPlayer (const IPlayer& visitable);
      virtual void VisitTeleporter (const Teleporter& visitable);

    protected:

      BaseDynamicWorldObjectConstVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP
