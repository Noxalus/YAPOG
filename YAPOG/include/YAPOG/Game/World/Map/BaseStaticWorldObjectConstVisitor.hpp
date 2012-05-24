#ifndef YAPOG_BASESTATICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_BASESTATICWORLDOBJECTCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IStaticWorldObjectConstVisitor.hpp"

namespace yap
{
  class BaseStaticWorldObjectConstVisitor
    : public IStaticWorldObjectConstVisitor
  {
      DISALLOW_COPY(BaseStaticWorldObjectConstVisitor);

    public:

      virtual ~BaseStaticWorldObjectConstVisitor ();

      virtual void Visit (const MapElement& visitable);

    protected:

      BaseStaticWorldObjectConstVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASESTATICWORLDOBJECTCONSTVISITOR_HPP
