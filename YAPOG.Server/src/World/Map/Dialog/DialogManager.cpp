#include "World/Map/Dialog/DialogManager.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"

namespace yse
{
  DialogManager::DialogManager ()
    : packetHandler_ ()
    , speaker_ (nullptr)
    , listeners_ ()
  {
  }

  DialogManager::~DialogManager ()
  {
  }

  void DialogManager::SetDisplay (yap::IDialogDisplay& dialogDisplay)
  {
    dialogDisplay_ = &dialogDisplay;
  }

  void DialogManager::AddListener (yap::IDialogActor& dialogActor)
  {
    listeners_.Add (&dialogActor);
  }

  void DialogManager::StartDialog (
    yap::IDialogActor& dialogActor,
    yap::IDialogNode& dialogNode)
  {
    /// @todo

    speaker_ = &dialogActor;

    HandleStartDialog ();

    yap::IDialogNode* currentNode = &dialogNode;
    yap::DialogNodeExecutionContext dialogNodeExecutionContext;

    while (currentNode->Execute (dialogNodeExecutionContext))
    {
      dialogDisplay_->Display (
        dialogActor,
        dialogNodeExecutionContext.GetMessage ());

      if (dialogNodeExecutionContext.IsTerminal ())
        break;

      currentNode = &dialogNodeExecutionContext.GetNextNode ();
    }

    HandleStopDialog ();
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

  void DialogManager::HandleStartDialog ()
  {
  }

  void DialogManager::HandleStopDialog ()
  {
    speaker_->StopTalking ();

    for (yap::IDialogActor* listener : listeners_)
      listener->StopListening ();
  }
} // namespace yse
