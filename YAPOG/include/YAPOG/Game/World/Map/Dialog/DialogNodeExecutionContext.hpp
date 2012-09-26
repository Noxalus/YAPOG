#ifndef YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP
# define YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IDialogMessage;
  struct IDialogNode;
  struct IGameAction;

  class YAPOG_LIB DialogNodeExecutionContext
  {
    public:

      DialogNodeExecutionContext ();

      DialogNodeExecutionContext (
        const ID& id,
        const IDialogMessage& message,
        IGameAction* action,
        IDialogNode* nextNode);

      const ID& GetNodeID () const;

      const IDialogMessage& GetMessage () const;

      bool IsTerminal () const;

      bool ExecuteAction ();

      IDialogNode& GetNextNode ();

    private:

      ID id_;

      const IDialogMessage* message_;

      IGameAction* action_;

      IDialogNode* nextNode_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP
