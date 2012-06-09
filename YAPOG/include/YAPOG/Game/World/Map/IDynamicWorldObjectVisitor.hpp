#ifndef YAPOG_IDYNAMICWORLDOBJECTVISITOR_HPP
# define YAPOG_IDYNAMICWORLDOBJECTVISITOR_HPP

namespace yap
{
  struct IPlayer;

  class Character;
  class Teleporter;

  struct IDynamicWorldObjectVisitor
  {
      virtual ~IDynamicWorldObjectVisitor () { }

      virtual void VisitCharacter (Character& visitable) = 0;
      virtual void VisitPlayer (IPlayer& visitable) = 0;
      virtual void VisitTeleporter (Teleporter& visitable) = 0;
  };
} // namespace yap

#endif // YAPOG_IDYNAMICWORLDOBJECTVISITOR_HPP
