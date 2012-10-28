#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNode.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogNodeConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogResponse.hpp"
#include "YAPOG/Game/World/Map/Dialog/IDialogManager.hpp"
#include "YAPOG/Game/World/Map/Dialog/ResponseHandlerDialogNodeEntry.hpp"

namespace yap
{
  ResponseHandlerDialogNode::ResponseHandlerDialogNode ()
    : entries_ ()
    , currentEntry_ (nullptr)
  {
  }

  ResponseHandlerDialogNode::~ResponseHandlerDialogNode ()
  {
  }

  ResponseHandlerDialogNode::ResponseHandlerDialogNode (
    const ResponseHandlerDialogNode& copy)
    : entries_ ()
    , currentEntry_ (nullptr)
  {
    for (auto entry : copy.entries_)
      AddEntry (new ResponseHandlerDialogNodeEntry (*entry));
  }

  ResponseHandlerDialogNode* ResponseHandlerDialogNode::Clone () const
  {
    return new ResponseHandlerDialogNode (*this);
  }

  void ResponseHandlerDialogNode::AddEntry (
    ResponseHandlerDialogNodeEntry* entry)
  {
    entries_.Add (entry);
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

  DialogNodeExecutionStatus ResponseHandlerDialogNode::Execute (
    IDialogManager& dialogManager,
    DialogNodeExecutionContext& executionContext)
  {
    for (EntryCollectionType::SizeType count = 0;
         count < entries_.Count ();
         ++count)
    {
      ResponseHandlerDialogNodeEntry* entry = entries_[count];

      if (!entry->RequirementIsFulfilled ())
        continue;

      ID entryID = ID (count);

      SetCurrentEntry (entryID);

      executionContext = DialogNodeExecutionContext (
        entryID,
        entry->GetMessages (),
        entry->Action,
        nullptr);

      dialogManager.TreatResponseProvider (*this);

      return DialogNodeExecutionStatus::Waiting;
    }

    return DialogNodeExecutionStatus::Over;
  }

  const collection::Array<IDialogResponse*>&
  ResponseHandlerDialogNode::GetResponses () const
  {
    return currentEntry_->GetResponses ();
  }

  IDialogNode& ResponseHandlerDialogNode::GetNextNode (const ID& responseID)
  {
    return currentEntry_->GetNextNode (responseID);
  }

  void ResponseHandlerDialogNode::SetCurrentEntry (const ID& entryID)
  {
    currentEntry_ = entries_[entryID.GetValue ()];
  }
} // namespace yap
