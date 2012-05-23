#ifndef YAPOG_IDYNAMICWORLDOBJECTREADER_HPP
# define YAPOG_IDYNAMICWORLDOBJECTREADER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class Character;

  struct IDynamicWorldObjectVisitor
  {
      virtual ~IDynamicWorldObjectVisitor () {}

      virtual void Visit (Character& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDYNAMICWORLDOBJECTREADER_HPP
