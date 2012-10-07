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
      DISALLOW_ASSIGN(DialogNode);

    public:

      DialogNode ();

      virtual ~DialogNode ();

      void AddEntry (DialogNodeEntry* entry);

      /// @name IDialogNode members.
      /// @{
      virtual bool Accept (IDialogNodeVisitor<bool>& visitor);
      virtual bool Accept (IDialogNodeConstVisitor<bool>& visitor) const;

      virtual DialogNodeExecutionStatus Execute (
        IDialogManager& dialogManager,
        DialogNodeExecutionContext& executionContext);
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual DialogNode* Clone () const;
      /// @}

    protected:

      DialogNode (const DialogNode& copy);

    private:

      typedef yap::collection::Array<DialogNodeEntry*> EntryCollectionType;

      EntryCollectionType entries_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODE_HPP
