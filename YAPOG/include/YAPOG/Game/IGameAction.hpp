#ifndef YAPOG_IGAMEACTION_HPP
# define YAPOG_IGAMEACTION_HPP

namespace yap
{
  struct IGameAction
  {
      virtual ~IGameAction () { }

      virtual bool Execute () = 0;
  };
} // namespace yap

#endif // YAPOG_IGAMEACTION_HPP
