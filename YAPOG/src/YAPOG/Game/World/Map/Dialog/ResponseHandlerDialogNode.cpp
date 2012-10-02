#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponse.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponseAcceptor.hpp"

namespace yap
{
  ResponseHandlerDialogNode::ResponseHandlerDialogNode (
    IDialogResponseAcceptor& responseAcceptor)
    : responses_ ()
    , entries_ ()
    , responseAcceptor_ (responseAcceptor)
  {
  }

  ResponseHandlerDialogNode::~ResponseHandlerDialogNode ()
  {
  }

  ResponseHandlerDialogNode::ResponseHandlerDialogNode (
    const ResponseHandlerDialogNode& copy)
    : responses_ ()
    , entries_ ()
    , responseAcceptor_ (copy.responseAcceptor_)
  {
    for (const auto& entry : copy.entries_)
      AddEntry (entry.first->Clone (), entry.second->Clone ());
  }

  ResponseHandlerDialogNode* ResponseHandlerDialogNode::Clone () const
  {
    return new ResponseHandlerDialogNode (*this);
  }

  bool ResponseHandlerDialogNode::ExecuteResponse (
    const ID& responseID,
    DialogNodeExecutionContext& executionContext)
  {
    return entries_[responses_[responseID.GetValue ()]]->Execute (
      executionContext);
  }

  void ResponseHandlerDialogNode::AddEntry (
    IDialogResponse* dialogResponse,
    IDialogNode* dialogNode)
  {
    responses_.Add (dialogResponse);

    entries_.Add (dialogResponse, dialogNode);
  }

  bool ResponseHandlerDialogNode::Accept (IDialogNodeVisitor<bool>& visitor)
  {
    return visitor.VisitResponseHandlerDialogNode (*this);
  }

  bool ResponseHandlerDialogNode::Accept (
    IDialogNodeConstVisitor<bool>& visitor) const
  {
    return visitor.VisitResponseHandlerDialogNode (*this);
  }

  bool ResponseHandlerDialogNode::Execute (
    DialogNodeExecutionContext& executionContext)
  {
    responseAcceptor_.TreatNode (*this);

    return false;
  }
} // namespace yap
