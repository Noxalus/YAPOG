#ifndef YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  class Character;

  class BaseDynamicWorldObjectConstVisitor
    : public IDynamicWorldObjectConstVisitor
  {
      DISALLOW_COPY(BaseDynamicWorldObjectConstVisitor);

    public:

      virtual ~BaseDynamicWorldObjectConstVisitor ();

      virtual void Visit (const Character& visitable);

    protected:

      BaseDynamicWorldObjectConstVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEDYNAMICWORLDOBJECTCONSTVISITOR_HPP
