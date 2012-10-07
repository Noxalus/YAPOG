#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponse.hpp"
#include "YAPOG/Game/IGameRequirement.hpp"
#include "YAPOG/Game/IGameAction.hpp"

namespace yap
{
  ResponseHandlerDialogNodeEntry::ResponseHandlerDialogNodeEntry (
    IGameRequirement* requirement,
    IGameAction* action)
    : Action (action)
    , requirement_ (requirement)
    , messages_ ()
    , responses_ ()
    , nextNodes_ ()
  {
  }

  ResponseHandlerDialogNodeEntry::~ResponseHandlerDialogNodeEntry ()
  {
    delete Action;
    Action = nullptr;

    delete requirement_;
    requirement_ = nullptr;

    for (auto message : messages_)
      delete message;

    for (const auto& responseNodePair : nextNodes_)
    {
      delete responseNodePair.first;
      delete responseNodePair.second;
    }
  }

  ResponseHandlerDialogNodeEntry::ResponseHandlerDialogNodeEntry (
    const ResponseHandlerDialogNodeEntry& copy)
    : Action (copy.Action == nullptr ? nullptr : copy.Action->Clone ())
    , requirement_ (
        copy.requirement_ == nullptr ? nullptr : copy.requirement_->Clone ())
    , messages_ ()
    , responses_ ()
    , nextNodes_ ()
  {
    for (auto message : copy.messages_)
      AddMessage (message->Clone ());

    for (const auto& responseNodePair : copy.nextNodes_)
      AddResponse (
        responseNodePair.first->Clone (),
        responseNodePair.second->Clone ());
  }

  bool ResponseHandlerDialogNodeEntry::RequirementIsFulfilled ()
  {
    return requirement_ == nullptr ? true : requirement_->IsFulfilled ();
  }

  void ResponseHandlerDialogNodeEntry::AddMessage (
    const IDialogMessage* message)
  {
    messages_.Add (message);
  }

  const ResponseHandlerDialogNodeEntry::MessageCollectionType&
  ResponseHandlerDialogNodeEntry::GetMessages () const
  {
    return messages_;
  }

  void ResponseHandlerDialogNodeEntry::AddResponse (
    IDialogResponse* response,
    IDialogNode* nextNode)
  {
    responses_.Add (response);
    nextNodes_.Add (response, nextNode);
  }

  const ResponseHandlerDialogNodeEntry::ResponseCollection&
  ResponseHandlerDialogNodeEntry::GetResponses () const
  {
    return responses_;
  }

  IDialogNode& ResponseHandlerDialogNodeEntry::GetNextNode (
    const ID& responseID)
  {
    return *nextNodes_[responses_[responseID.GetValue ()]];
  }
} // namespace yap
