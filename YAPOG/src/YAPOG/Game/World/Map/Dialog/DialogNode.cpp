#include "YAPOG/Game/World/Map/Dialog/DialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/DialogNodeEntry.hpp"

namespace yap
{
  DialogNode::DialogNode ()
  {
  }

  DialogNode::~DialogNode ()
  {
  }

  DialogNode& DialogNode::AddEntry (DialogNodeEntry* entry)
  {
    entries_.Add (entry);

    return *this;
  }

  bool DialogNode::Accept (IDialogNodeVisitor<bool>& visitor)
  {
    return visitor.VisitDialogNode (*this);
  }

  bool DialogNode::Accept (IDialogNodeConstVisitor<bool>& visitor) const
  {
    return visitor.VisitDialogNode (*this);
  }

  bool DialogNode::Execute (DialogNodeExecutionContext& executionContext)
  {
    for (DialogNodeEntry* entry : entries_)
    {
      if (!entry->RequirementIsFulfilled ())
        continue;

      executionContext = DialogNodeExecutionContext (
        *entry->Message,
        entry->Action,
        entry->NextNode);

      return true;
    }

    return false;
  }
} // namespace yap
