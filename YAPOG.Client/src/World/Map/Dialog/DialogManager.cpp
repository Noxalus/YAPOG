#include "World/Map/Dialog/DialogManager.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponseProvider.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeExecutionContext.hpp"
#include "YAPOG/System/Network/IPacket.hpp"
#include "YAPOG/System/Network/Packet.hpp"

namespace ycl
{
  DialogManager::DialogManager ()
    : packetHandler_ ()
    , dialogDisplay_ (nullptr)
    , currentNode_ (nullptr)
    , currentNodeID_ ()
    , speaker_ (nullptr)
    , listeners_ ()
    , currentResponseProvider_ (nullptr)
  {
    ADD_HANDLER (
      ServerInfoStopDialog,
      DialogManager::HandleServerInfoStopDialog);
    ADD_HANDLER (
      ServerInfoChangeDialogNode,
      DialogManager::HandleServerInfoChangeDialogNode);
  }

  DialogManager::~DialogManager ()
  {
  }

  void DialogManager::SetDisplay (yap::IDialogDisplay* dialogDisplay)
  {
    dialogDisplay_ = dialogDisplay;

    dialogDisplay_->OnResponseReceivedEvent () += [this] (
      yap::IDialogDisplay& sender,
      const yap::ID& args)
    {
      HandleOnResponseReceived (args);
    };
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

    currentNode_ = &dialogNode;
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

  void DialogManager::ExecuteCurrentNode ()
  {
    yap::DialogNodeExecutionContext dialogNodeExecutionContext;

    switch (currentNode_->Execute (*this, dialogNodeExecutionContext))
    {
      case yap::DialogNodeExecutionStatus::Running:

        if (dialogNodeExecutionContext.GetNodeID () != currentNodeID_)
          return;

        for (auto message : dialogNodeExecutionContext.GetMessages ())
          dialogDisplay_->Display (
            *speaker_,
            *message);

        currentNode_ = &dialogNodeExecutionContext.GetNextNode ();

        break;

      case yap::DialogNodeExecutionStatus::Waiting:

        if (dialogNodeExecutionContext.GetNodeID () != currentNodeID_)
          return;

        for (auto message : dialogNodeExecutionContext.GetMessages ())
          dialogDisplay_->Display (
            *speaker_,
            *message);

        dialogDisplay_->Display (
          *speaker_,
          currentResponseProvider_->GetResponses ());

        break;

      case yap::DialogNodeExecutionStatus::Over:

        break;
    }
  }

  void DialogManager::ChangeNode (const yap::ID& nodeID)
  {
    currentNodeID_ = nodeID;
  }

  void DialogManager::HandleOnResponseReceived (const yap::ID& responseID)
  {
    currentNode_ = &currentResponseProvider_->GetNextNode (responseID);

    SendResponseReceived (responseID);
  }

  void DialogManager::StopDialog ()
  {
    currentNode_ = nullptr;

    speaker_ = nullptr;
    listeners_.Clear ();

    currentResponseProvider_ = nullptr;
  }

  void DialogManager::HandleServerInfoStopDialog (yap::IPacket& packet)
  {
    StopDialog ();
  }

  void DialogManager::HandleServerInfoChangeDialogNode (yap::IPacket& packet)
  {
    yap::ID currenNodeID = packet.ReadID ();

    ChangeNode (currenNodeID);

    ExecuteCurrentNode ();
  }

  void DialogManager::UnsetDisplay ()
  {
    if (dialogDisplay_ == nullptr)
      return;

    /// @todo remove event handlers

    delete dialogDisplay_;
    dialogDisplay_ = nullptr;
  }

  void DialogManager::SendResponseReceived (const yap::ID& responseID)
  {
    yap::Packet packet;
    packet.CreateFromType (yap::PacketType::ClientInfoDialogResponse);

    packet.Write (responseID);

    SendPacket (packet);
  }
} // namespace ycl
