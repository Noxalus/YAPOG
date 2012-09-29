#include "World/Map/Dialog/DialogManager.hpp"

#include "YAPOG/Game/World/Map/Dialog/IDialogDisplay.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeExecutionContext.hpp"
#include "YAPOG/System/Network/IPacket.hpp"

namespace ycl
{
  DialogManager::DialogManager ()
    : packetHandler_ ()
    , dialogDisplay_ (nullptr)
    , currentNode_ (nullptr)
    , currentNodeID_ ()
    , speaker_ (nullptr)
    , listeners_ ()
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

    if (!currentNode_->Execute (dialogNodeExecutionContext))
      return;

    if (dialogNodeExecutionContext.GetNodeID () != currentNodeID_)
      return;

    dialogDisplay_->Display (
      *speaker_,
      dialogNodeExecutionContext.GetMessage ());

    currentNode_ = &dialogNodeExecutionContext.GetNextNode ();
  }

  void DialogManager::ChangeNode (const yap::ID& nodeID)
  {
    currentNodeID_ = nodeID;
  }

  void DialogManager::StopDialog ()
  {
    currentNode_ = nullptr;

    speaker_ = nullptr;
    listeners_.Clear ();
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
} // namespace ycl
