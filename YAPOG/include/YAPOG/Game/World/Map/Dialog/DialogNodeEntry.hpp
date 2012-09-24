#ifndef YAPOG_DIALOGNODEENTRY_HPP
# define YAPOG_DIALOGNODEENTRY_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct IDialogMessage;
  struct IDialogNode;
  struct IGameRequirement;
  struct IGameAction;

  class DialogNodeEntry
  {
      DISALLOW_ASSIGN(DialogNodeEntry);

    public:

      DialogNodeEntry (
        const IDialogMessage* const message,
        IGameRequirement* requirement,
        IGameAction* action,
        IDialogNode* next);

      ~DialogNodeEntry ();

      DialogNodeEntry (const DialogNodeEntry& copy);

      bool RequirementIsFulfilled ();

      const IDialogMessage* const Message;

      IGameAction* Action;

      IDialogNode* NextNode;

    private:

      IGameRequirement* requirement_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODEENTRY_HPP
