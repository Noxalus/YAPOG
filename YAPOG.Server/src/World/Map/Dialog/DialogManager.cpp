#include "World/Map/Dialog/DialogManager.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogActor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponseProvider.hpp"
#include "YAPOG/System/Network/Packet.hpp"

namespace yse
{
  DialogManager::DialogManager ()
    : packetHandler_ ()
    , dialogDisplay_ (nullptr)
    , speaker_ (nullptr)
    , listeners_ ()
    , currentResponseProvider_ (nullptr)
  {
    ADD_HANDLER(
      ClientInfoDialogResponse,
      DialogManager::HandleClientInfoDialogResponse);
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

  void DialogManager::TreatResponseProvider (
    yap::IDialogResponseProvider& dialogResponseProvider)
  {
    currentResponseProvider_ = &dialogResponseProvider;
  }

  void DialogManager::StartDialog (
    yap::IDialogActor& dialogActor,
    yap::IDialogNode& dialogNode)
  {
    speaker_ = &dialogActor;

    HandleStartDialog ();

    ExecuteNode (dialogNode);
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

    currentResponseProvider_ = nullptr;
  }

  void DialogManager::ExecuteNode (yap::IDialogNode& dialogNode)
  {
    yap::IDialogNode* currentNode = &dialogNode;

    yap::DialogNodeExecutionStatus executionStatus;
    yap::DialogNodeExecutionContext dialogNodeExecutionContext;

    do
    {
      executionStatus = currentNode->Execute (
        *this,
        dialogNodeExecutionContext);

      switch (executionStatus)
      {
        case yap::DialogNodeExecutionStatus::Running:

          for (auto message : dialogNodeExecutionContext.GetMessages ())
            dialogDisplay_->Display (
              *speaker_,
              *message);

          SendChangeDialogNode (dialogNodeExecutionContext.GetNodeID ());

          if (dialogNodeExecutionContext.IsTerminal ())
          {
            HandleStopDialog ();

            return;
          }

          currentNode = &dialogNodeExecutionContext.GetNextNode ();

          break;

        case yap::DialogNodeExecutionStatus::Waiting:

          for (auto message : dialogNodeExecutionContext.GetMessages ())
            dialogDisplay_->Display (
              *speaker_,
              *message);

          SendChangeDialogNode (dialogNodeExecutionContext.GetNodeID ());

          break;

        case yap::DialogNodeExecutionStatus::Over:

          HandleStopDialog ();

          break;

        default: break;
      }
    } while (executionStatus == yap::DialogNodeExecutionStatus::Running);
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

  void DialogManager::HandleClientInfoDialogResponse (yap::IPacket& packet)
  {
    yap::ID responseID = packet.ReadID ();

    ExecuteNode (currentResponseProvider_->GetNextNode (responseID));
  }
} // namespace yse
