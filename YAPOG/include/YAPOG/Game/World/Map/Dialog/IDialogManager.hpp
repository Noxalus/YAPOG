#ifndef YAPOG_IDIALOGMANAGER_HPP
# define YAPOG_IDIALOGMANAGER_HPP

# include "YAPOG/Game/World/Map/Dialog/IDialogResponseAcceptor.hpp"

namespace yap
{
  struct IDialogActor;
  struct IDialogNode;

  struct IDialogManager : public IDialogResponseAcceptor
  {
      virtual ~IDialogManager () { }

      virtual void StartDialog (
        IDialogActor& dialogActor,
        IDialogNode& dialogNode) = 0;
  };
} // namespace yap

#endif // YAPOG_IDIALOGMANAGER_HPP
