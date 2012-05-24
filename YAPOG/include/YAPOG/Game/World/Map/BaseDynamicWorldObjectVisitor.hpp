#ifndef YAPOG_BASEDYNAMICWORLDOBJECTVISITOR_HPP
# define YAPOG_BASEDYNAMICWORLDOBJECTVISITOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"

namespace yap
{
  class Character;

  class BaseDynamicWorldObjectVisitor : public IDynamicWorldObjectVisitor
  {
      DISALLOW_COPY(BaseDynamicWorldObjectVisitor);

    public:

      virtual ~BaseDynamicWorldObjectVisitor ();

      virtual void Visit (Character& visitable);

    protected:

      BaseDynamicWorldObjectVisitor ();
  };
} // namespace yap

#endif // YAPOG_BASEDYNAMICWORLDOBJECTVISITOR_HPP
