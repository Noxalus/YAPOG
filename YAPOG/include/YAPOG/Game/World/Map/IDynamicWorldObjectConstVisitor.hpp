#ifndef YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class Character;

  struct IDynamicWorldObjectConstVisitor
  {
      virtual ~IDynamicWorldObjectConstVisitor () {}

      virtual void Visit (const Character& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP
