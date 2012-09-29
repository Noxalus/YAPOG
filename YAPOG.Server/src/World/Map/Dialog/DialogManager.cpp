#include "World/Map/Dialog/DialogManager.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"
#include "YAPOG/System/Network/Packet.hpp"

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

  void DialogManager::SetDisplay (yap::IDialogDisplay* dialogDisplay)
  {
    dialogDisplay_ = dialogDisplay;
  }

  void DialogManager::AddListener (yap::IDialogActor& dialogActor)
  {
    listeners_.Add (&dialogActor);
  }

  void DialogManager::StartDialog (
    yap::IDialogActor& dialogActor,
    yap::IDialogNode& dialogNode)
  {
    speaker_ = &dialogActor;

    HandleStartDialog ();

    yap::IDialogNode* currentNode = &dialogNode;
    yap::DialogNodeExecutionContext dialogNodeExecutionContext;

    while (currentNode->Execute (dialogNodeExecutionContext))
    {
      dialogDisplay_->Display (
        *speaker_,
        dialogNodeExecutionContext.GetMessage ());

      SendChangeDialogNode (dialogNodeExecutionContext.GetNodeID ());

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
    SendStartDialog ();
  }

  void DialogManager::HandleStopDialog ()
  {
    SendStopDialog ();

    speaker_->StopTalking ();

    for (yap::IDialogActor* listener : listeners_)
      listener->StopListening ();

    speaker_ = nullptr;
    listeners_.Clear ();
  }

  void DialogManager::SendStartDialog ()
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoStartDialog);

    packet.Write (speaker_->GetWorldID ());

    SendPacket (packet);
  }

  void DialogManager::SendStopDialog ()
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoStopDialog);

    SendPacket (packet);
  }

  void DialogManager::SendChangeDialogNode (const yap::ID& dialogNodeID)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ServerInfoChangeDialogNode);

    packet.Write (dialogNodeID);

    SendPacket (packet);
  }
} // namespace yse
