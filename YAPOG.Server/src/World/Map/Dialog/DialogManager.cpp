#include "World/Map/Dialog/DialogManager.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"

namespace yse
{
  DialogManager::DialogManager ()
    : packetHandler_ ()
  {
  }

  DialogManager::~DialogManager ()
  {
  }

  void DialogManager::SetDisplay (yap::IDialogDisplay& dialogDisplay)
  {
    dialogDisplay_ = &dialogDisplay;
  }

  void DialogManager::StartDialog (
    yap::IDialogActor& dialogActor,
    yap::IDialogNode& dialogNode)
  {
    yap::DialogNodeExecutionContext dialogNodeExecutionContext;

    if (!dialogNode.Execute (dialogNodeExecutionContext))
      return;

    dialogDisplay_->Display (
      dialogActor,
      dialogNodeExecutionContext.GetMessage ());
  }

  bool DialogManager::HandlePacket (yap::IPacket& packet)
  {
    return packetHandler_.HandlePacket (packet);
  }

  bool DialogManager::SendPacket (yap::IPacket& packet)
  {
    return packetHandler_.SendPacket (packet);
  }

  void DialogManager::AddRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.AddRelay (relay);
  }

  void DialogManager::RemoveRelay (yap::IPacketHandler* relay)
  {
    packetHandler_.RemoveRelay (relay);
  }

  void DialogManager::SetParent (yap::IPacketHandler* parent)
  {
    packetHandler_.SetParent (parent);
  }
} // namespace yse
