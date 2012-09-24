#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogMessage.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
#include "YAPOG/Game/IGameRequirement.hpp"
#include "YAPOG/Game/IGameAction.hpp"

namespace yap
{
  DialogNodeEntry::DialogNodeEntry (
    const IDialogMessage* const message,
    IGameRequirement* requirement,
    IGameAction* action,
    IDialogNode* next)
    : Message (message)
    , Action (action)
    , NextNode (next)
    , requirement_ (requirement)
  {
  }

  DialogNodeEntry::~DialogNodeEntry ()
  {
    delete Message;

    delete Action;
    Action = nullptr;

    delete NextNode;
    NextNode = nullptr;

    delete requirement_;
    requirement_ = nullptr;
  }

  DialogNodeEntry::DialogNodeEntry (const DialogNodeEntry& copy)
    : Message (copy.Message->Clone ())
    , Action (copy.Action == nullptr ? nullptr : copy.Action->Clone ())
    , NextNode (copy.NextNode == nullptr ? nullptr : copy.NextNode->Clone ())
    , requirement_ (
        copy.requirement_ == nullptr ? nullptr : copy.requirement_->Clone ())
  {
  }

  bool DialogNodeEntry::RequirementIsFulfilled ()
  {
    return requirement_ == nullptr ? true : requirement_->IsFulfilled ();
  }
} // namespace yap
