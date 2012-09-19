#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"
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
  }

  bool DialogNodeEntry::RequirementIsFulfilled ()
  {
    return requirement_ == nullptr ? true : requirement_->IsFulfilled ();
  }
} // namespace yap
