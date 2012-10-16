#ifndef YAPOG_RESPONSEHANDLERDIALOGNODE_HPP
# define YAPOG_RESPONSEHANDLERDIALOGNODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogResponseProvider.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  struct IDialogResponse;

  class ResponseHandlerDialogNodeEntry;

  class YAPOG_LIB ResponseHandlerDialogNode : public IDialogNode
                                            , public IDialogResponseProvider
  {
      DISALLOW_ASSIGN(ResponseHandlerDialogNode);

    public:

      ResponseHandlerDialogNode ();

      virtual ~ResponseHandlerDialogNode ();

      void AddEntry (ResponseHandlerDialogNodeEntry* entry);

      /// @name ICloneable members.
      /// @{
      virtual ResponseHandlerDialogNode* Clone () const;
      /// @}

      /// @name IDialogNode members.
      /// @{
      virtual bool Accept (IDialogNodeVisitor<bool>& visitor);
      virtual bool Accept (IDialogNodeConstVisitor<bool>& visitor) const;

      virtual DialogNodeExecutionStatus Execute (
        IDialogManager& dialogManager,
        DialogNodeExecutionContext& executionContext);
      /// @}

      /// @name IDialogResponseProvider members.
      /// @{
      virtual const collection::Array<
        IDialogResponse*>& GetResponses () const;

      virtual IDialogNode& GetNextNode (const ID& responseID);
      /// @}

    protected:

      ResponseHandlerDialogNode (const ResponseHandlerDialogNode& copy);

    private:

      typedef
        collection::Array<ResponseHandlerDialogNodeEntry*> EntryCollectionType;

      void SetCurrentEntry (const ID& entryID);

      EntryCollectionType entries_;

      ResponseHandlerDialogNodeEntry* currentEntry_;
  };
} // namespace yap

#endif // YAPOG_RESPONSEHANDLERDIALOGNODE_HPP
