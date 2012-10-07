#ifndef YAPOG_RESPONSEHANDLERDIALOGNODEENTRY_HPP
# define YAPOG_RESPONSEHANDLERDIALOGNODEENTRY_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Collection/Array.hpp"
# include "YAPOG/Collection/Map.hpp"
# include "YAPOG/Game/ID.hpp"

namespace yap
{
  struct IDialogMessage;
  struct IDialogNode;
  struct IDialogResponse;
  struct IGameRequirement;
  struct IGameAction;

  class ResponseHandlerDialogNodeEntry
  {
      DISALLOW_ASSIGN(ResponseHandlerDialogNodeEntry);

    public:

      typedef collection::Array<const IDialogMessage*> MessageCollectionType;
      typedef collection::Array<IDialogResponse*> ResponseCollection;

      ResponseHandlerDialogNodeEntry (
        IGameRequirement* requirement,
        IGameAction* action);

      ~ResponseHandlerDialogNodeEntry ();

      ResponseHandlerDialogNodeEntry (
        const ResponseHandlerDialogNodeEntry& copy);

      bool RequirementIsFulfilled ();

      void AddMessage (const IDialogMessage* message);
      const MessageCollectionType& GetMessages () const;

      IGameAction* Action;

      void AddResponse (IDialogResponse* response, IDialogNode* nextNode);
      const ResponseCollection& GetResponses () const;
      IDialogNode& GetNextNode (const ID& responseID);

    private:

      typedef collection::Map<IDialogResponse*, IDialogNode*> ResponseNodeMap;

      IGameRequirement* requirement_;

      MessageCollectionType messages_;

      ResponseCollection responses_;
      ResponseNodeMap nextNodes_;
  };
} // namespace yap

#endif // YAPOG_RESPONSEHANDLERDIALOGNODEENTRY_HPP
