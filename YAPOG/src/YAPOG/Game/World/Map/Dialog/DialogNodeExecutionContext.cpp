#include "YAPOG/Game/World/Map/Dialog/DialogNodeExecutionContext.hpp"
#include "YAPOG/Game/IGameAction.hpp"

namespace yap
{
  DialogNodeExecutionContext::DialogNodeExecutionContext ()
    : id_ ()
    , message_ (nullptr)
    , action_ (nullptr)
    , nextNode_ (nullptr)
  {
  }

  DialogNodeExecutionContext::DialogNodeExecutionContext (
    const ID& id,
    const IDialogMessage& message,
    IGameAction* action,
    IDialogNode* nextNode)
    : id_ (id)
    , message_ (&message)
    , action_ (action)
    , nextNode_ (nextNode)
  {
  }

  const ID& DialogNodeExecutionContext::GetNodeID () const
  {
    return id_;
  }

  const IDialogMessage& DialogNodeExecutionContext::GetMessage () const
  {
    return *message_;
  }

  bool DialogNodeExecutionContext::IsTerminal () const
  {
    return nextNode_ == nullptr;
  }

  bool DialogNodeExecutionContext::ExecuteAction ()
  {
    return action_ == nullptr ? true : action_->Execute ();
  }

  IDialogNode& DialogNodeExecutionContext::GetNextNode ()
  {
    return *nextNode_;
  }
} // namespace yap
