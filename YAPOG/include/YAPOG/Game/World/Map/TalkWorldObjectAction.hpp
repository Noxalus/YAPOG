#ifndef YAPOG_TALKWORLDOBJECTACTION_HPP
# define YAPOG_TALKWORLDOBJECTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObjectAction.hpp"

namespace yap
{
  struct IDialogActor;
  struct IDialogManager;

  class TalkWorldObjectAction : public WorldObjectAction
  {
      DISALLOW_COPY(TalkWorldObjectAction);

    public:

      virtual ~TalkWorldObjectAction ();

    protected:

      TalkWorldObjectAction (
        DynamicWorldObject& parent,
        IDialogActor& dialogActor,
        IDialogManager& dialogManager);

      virtual void HandlePerform ();

    private:

      IDialogActor& dialogActor_;
      IDialogManager& dialogManager_;
  };
} // namespace yap

#endif // YAPOG_TALKWORLDOBJECTACTION_HPP
