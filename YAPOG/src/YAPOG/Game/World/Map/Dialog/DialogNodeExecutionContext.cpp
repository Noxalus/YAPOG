#include "YAPOG/Game/World/Map/Dialog/DialogNodeExecutionContext.hpp"
#include "YAPOG/Game/IGameAction.hpp"

namespace yap
{
  DialogNodeExecutionContext::DialogNodeExecutionContext ()
    : id_ ()
    , messages_ ()
    , action_ (nullptr)
    , nextNode_ (nullptr)
  {
  }

  DialogNodeExecutionContext::DialogNodeExecutionContext (
    const ID& id,
    const MessageCollectionType& messages,
    IGameAction* action,
    IDialogNode* nextNode)
    : id_ (id)
    , messages_ (messages)
    , action_ (action)
    , nextNode_ (nextNode)
  {
  }

  const ID& DialogNodeExecutionContext::GetNodeID () const
  {
    return id_;
  }

  const DialogNodeExecutionContext::MessageCollectionType&
  DialogNodeExecutionContext::GetMessages () const
  {
    return messages_;
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
