#ifndef YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP
# define YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Collection/Array.hpp"

namespace yap
{
  struct IDialogMessage;
  struct IDialogNode;
  struct IGameAction;

  class YAPOG_LIB DialogNodeExecutionContext
  {
    public:

      typedef collection::Array<const IDialogMessage*> MessageCollectionType;

      DialogNodeExecutionContext ();

      DialogNodeExecutionContext (
        const ID& id,
        const MessageCollectionType& messages,
        IGameAction* action,
        IDialogNode* nextNode);

      const ID& GetNodeID () const;

      const MessageCollectionType& GetMessages () const;

      bool IsTerminal () const;

      bool ExecuteAction ();

      IDialogNode& GetNextNode ();

    private:

      ID id_;

      MessageCollectionType messages_;

      IGameAction* action_;

      IDialogNode* nextNode_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP
