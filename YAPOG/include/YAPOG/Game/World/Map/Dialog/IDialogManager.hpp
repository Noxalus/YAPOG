#ifndef YAPOG_IDIALOGMANAGER_HPP
# define YAPOG_IDIALOGMANAGER_HPP

namespace yap
{
  struct IDialogActor;
  struct IDialogNode;

  struct IDialogManager
  {
      virtual ~IDialogManager () { }

      virtual void StartDialog (
        IDialogActor& dialogActor,
        IDialogNode& dialogNode) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGMANAGER_HPP
