#ifndef YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP
# define YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP

namespace yap
{
  struct IPlayer;

  class Character;

  struct IDynamicWorldObjectConstVisitor
  {
      virtual ~IDynamicWorldObjectConstVisitor () { }

      virtual void VisitCharacter (const Character& visitable) = 0;
      virtual void VisitPlayer (const IPlayer& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDYNAMICWORLDOBJECTCONSTVISITOR_HPP
