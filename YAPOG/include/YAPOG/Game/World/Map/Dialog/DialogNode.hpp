#ifndef YAPOG_DIALOGNODE_HPP
# define YAPOG_DIALOGNODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  class DialogNodeEntry;

  class DialogNode : public IDialogNode
  {
      DISALLOW_COPY(DialogNode);

    public:

      DialogNode ();
      virtual ~DialogNode ();

      DialogNode& AddEntry (DialogNodeEntry* entry);

      /// @name IDialogNode members.
      /// @{
      virtual bool Accept (IDialogNodeVisitor<bool>& visitor);
      virtual bool Accept (IDialogNodeConstVisitor<bool>& visitor) const;

      virtual bool Execute (DialogNodeExecutionContext& executionContext);
      /// @}

    private:

      typedef yap::collection::Array<DialogNodeEntry*> EntryCollection;

      EntryCollection entries_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODE_HPP
