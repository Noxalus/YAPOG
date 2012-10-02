#ifndef YAPOG_RESPONSEHANDLERDIALOGNODE_HPP
# define YAPOG_RESPONSEHANDLERDIALOGNODE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Dialog/IDialogNode.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  struct IDialogResponse;
  struct IDialogResponseAcceptor;

  class ResponseHandlerDialogNode : public IDialogNode
  {
      DISALLOW_ASSIGN(ResponseHandlerDialogNode);

    public:

      ResponseHandlerDialogNode (IDialogResponseAcceptor& responseAcceptor);

      virtual ~ResponseHandlerDialogNode ();

      bool ExecuteResponse (
        const ID& responseID,
        DialogNodeExecutionContext& executionContext);

      void AddEntry (IDialogResponse* dialogResponse, IDialogNode* dialogNode);

      /// @name IDialogNode members.
      /// @{
      virtual bool Accept (IDialogNodeVisitor<bool>& visitor);
      virtual bool Accept (IDialogNodeConstVisitor<bool>& visitor) const;

      virtual bool Execute (DialogNodeExecutionContext& executionContext);
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual ResponseHandlerDialogNode* Clone () const;
      /// @}

    protected:

      ResponseHandlerDialogNode (const ResponseHandlerDialogNode& copy);

    private:

      typedef collection::Array<IDialogResponse*> ResponseCollectionType;
      typedef
        collection::Map<IDialogResponse*, IDialogNode*> EntryCollectionType;

      ResponseCollectionType responses_;
      EntryCollectionType entries_;

      IDialogResponseAcceptor& responseAcceptor_;
  };
} // namespace yap

#endif // YAPOG_RESPONSEHANDLERDIALOGNODE_HPP
