#ifndef YAPOG_IDIALOGMANAGER_HPP
# define YAPOG_IDIALOGMANAGER_HPP

namespace yap
{
  struct IDialogManager
  {
      virtual ~IDialogManager () { }

      virtual void StartDialog (IDialogActor& dialogActor) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGMANAGER_HPP
