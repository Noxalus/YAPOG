#ifndef YAPOG_IWORLDOBJECTACTION_HPP
# define YAPOG_IWORLDOBJECTACTION_HPP

namespace yap
{
  struct IWorldObjectAction
  {
      virtual ~IWorldObjectAction () { }

      virtual void Perform () = 0;
  };
} // namespace yap

#endif // YAPOG_IWORLDOBJECTACTION_HPP
