#ifndef YAPOG_IDIALOGACTOR_HPP
# define YAPOG_IDIALOGACTOR_HPP

# include "YAPOG/System/String.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IDialogManager;

  struct IDialogActor
  {
      virtual ~IDialogActor () { }

      virtual const String& GetName () const = 0;

      virtual const ID& GetWorldID () const = 0;

      virtual bool CanTalk (IDialogActor& dialogActor) const = 0;
      virtual void Talk (IDialogActor& dialogActor) = 0;
      virtual void StopTalking () = 0;

      virtual bool CanListen (IDialogActor& dialogActor) const = 0;
      virtual void Listen (IDialogActor& dialogActor) = 0;
      virtual void StopListening () = 0;

      virtual bool TryStartDialog (IDialogManager& dialogManager) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGACTOR_HPP
