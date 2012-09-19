#ifndef YAPOG_IDIALOGDISPLAY_HPP
# define YAPOG_IDIALOGDISPLAY_HPP

namespace yap
{
  struct IDialogActor;
  struct IDialogMessage;

  struct IDialogDisplay
  {
      virtual ~IDialogDisplay () { }

      virtual void Display (
        const IDialogActor& actor,
        const IDialogMessage& message) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGDISPLAY_HPP
