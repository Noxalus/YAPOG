#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/IGameRequirement.hpp"
#include "YAPOG/Game/IGameAction.hpp"

namespace yap
{
  DialogNodeEntry::DialogNodeEntry (
    IGameRequirement* requirement,
    IGameAction* action,
    IDialogNode* next)
    : Action (action)
    , NextNode (next)
    , requirement_ (requirement)
    , messages_ ()
  {
  }

  DialogNodeEntry::~DialogNodeEntry ()
  {
    delete Action;
    Action = nullptr;

    delete NextNode;
    NextNode = nullptr;

    delete requirement_;
    requirement_ = nullptr;

    for (auto message : messages_)
      delete message;
  }

  DialogNodeEntry::DialogNodeEntry (const DialogNodeEntry& copy)
    : Action (copy.Action == nullptr ? nullptr : copy.Action->Clone ())
    , NextNode (copy.NextNode == nullptr ? nullptr : copy.NextNode->Clone ())
    , requirement_ (
        copy.requirement_ == nullptr ? nullptr : copy.requirement_->Clone ())
    , messages_ ()
  {
    for (auto message : copy.messages_)
      AddMessage (message->Clone ());
  }

  bool DialogNodeEntry::RequirementIsFulfilled ()
  {
    return requirement_ == nullptr ? true : requirement_->IsFulfilled ();
  }

  void DialogNodeEntry::AddMessage (const IDialogMessage* message)
  {
    messages_.Add (message);
  }

  const DialogNodeEntry::MessageCollectionType&
  DialogNodeEntry::GetMessages () const
  {
    return messages_;
  }
} // namespace yap
