#ifndef YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP
# define YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP

namespace yap
{
  struct IDialogMessage;
  struct IDialogNode;
  struct IGameAction;

  class DialogNodeExecutionContext
  {
    public:

      DialogNodeExecutionContext ();

      DialogNodeExecutionContext (
        const IDialogMessage& message,
        IGameAction* action,
        IDialogNode* nextNode);

      const IDialogMessage& GetMessage () const;

      bool IsTerminal () const;

      bool ExecuteAction ();

      IDialogNode& GetNextNode ();

    private:

      const IDialogMessage* message_;

      IGameAction* action_;

      IDialogNode* nextNode_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODEEXECUTIONCONTEXT_HPP
