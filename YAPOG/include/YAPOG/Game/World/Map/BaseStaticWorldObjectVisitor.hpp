#ifndef YAPOG_BASESTATICWORLDOBJECTVISITOR_HPP
# define YAPOG_BASESTATICWORLDOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IStaticWorldObjectVisitor.hpp"

namespace yap
{
  class MapElement;

  class BaseStaticWorldObjectVisitor : public IStaticWorldObjectVisitor
  {
      DISALLOW_COPY(BaseStaticWorldObjectVisitor);

    public:

      virtual ~BaseStaticWorldObjectVisitor ();

      virtual void VisitStaticWorldObject (StaticWorldObject& visitable);
      virtual void VisitMapElement (MapElement& visitable);

    protected:

      BaseStaticWorldObjectVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASESTATICWORLDOBJECTVISITOR_HPP
