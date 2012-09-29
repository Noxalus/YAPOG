#ifndef YAPOG_DIALOGNODEENTRY_HPP
# define YAPOG_DIALOGNODEENTRY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"

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

      typedef collection::Array<const IDialogMessage*> MessageCollectionType;

      DialogNodeEntry (
        IGameRequirement* requirement,
        IGameAction* action,
        IDialogNode* next);

      ~DialogNodeEntry ();

      DialogNodeEntry (const DialogNodeEntry& copy);

      bool RequirementIsFulfilled ();

      void AddMessage (const IDialogMessage* message);
      const MessageCollectionType& GetMessages () const;

      IGameAction* Action;

      IDialogNode* NextNode;

    private:

      IGameRequirement* requirement_;

      MessageCollectionType messages_;
  };
} // namespace yap

#endif // YAPOG_DIALOGNODEENTRY_HPP
