#ifndef YAPOG_ISTATICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_ISTATICWORLDOBJECTCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class StaticWorldObject;
  class MapElement;

  struct IStaticWorldObjectConstVisitor
  {
      virtual ~IStaticWorldObjectConstVisitor () {}

      virtual void VisitStaticWorldObject (
        const StaticWorldObject& visitable) = 0;
      virtual void VisitMapElement (const MapElement& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_ISTATICWORLDOBJECTCONSTVISITOR_HPP
