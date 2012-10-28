#ifndef YAPOG_IDIALOGDISPLAY_HPP
# define YAPOG_IDIALOGDISPLAY_HPP

# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/System/Event/Event.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IDialogActor;
  struct IDialogMessage;
  struct IDialogResponse;

  struct IDialogDisplay
  {
      virtual ~IDialogDisplay () { }

      virtual void Display (
        const IDialogActor& actor,
        const IDialogMessage& message) = 0;

      virtual void Display (
        const IDialogActor& actor,
        const collection::Array<IDialogResponse*>& responses) = 0;

      virtual Event<IDialogDisplay&, const ID&>&
      OnResponseReceivedEvent () = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGDISPLAY_HPP
