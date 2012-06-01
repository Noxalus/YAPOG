#ifndef YAPOG_ISTATICWORLDOBJECTVISITOR_HPP
# define YAPOG_ISTATICWORLDOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class MapElement;

  struct IStaticWorldObjectVisitor
  {
      virtual ~IStaticWorldObjectVisitor () {}

      virtual void Visit (MapElement& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_ISTATICWORLDOBJECTVISITOR_HPP
