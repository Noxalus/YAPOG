#ifndef YAPOG_IPLAYER_HPP
# define YAPOG_IPLAYER_HPP

namespace yap
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

  struct IPlayer
  {
      virtual ~IPlayer () { }

      virtual void Accept (IDynamicWorldObjectVisitor& visitor) = 0;
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const = 0;
  };
} // namespace yap

#endif // YAPOG_IPLAYER_HPP
