#ifndef YAPOG_ISTATICWORLDOBJECTVISITOR_HPP
# define YAPOG_ISTATICWORLDOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class StaticWorldObject;
  class MapElement;

  struct IStaticWorldObjectVisitor
  {
      virtual ~IStaticWorldObjectVisitor () {}

      virtual void VisitStaticWorldObject (StaticWorldObject& visitable) = 0;
      virtual void VisitMapElement (MapElement& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_ISTATICWORLDOBJECTVISITOR_HPP
