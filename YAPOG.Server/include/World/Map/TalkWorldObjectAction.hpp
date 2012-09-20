#ifndef YAPOG_SERVER_TALKWORLDOBJECTACTION_HPP
# define YAPOG_SERVER_TALKWORLDOBJECTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/TalkWorldObjectAction.hpp"

namespace yse
{
  class TalkWorldObjectAction : public yap::TalkWorldObjectAction
  {
      DISALLOW_COPY(TalkWorldObjectAction);

    public:

      TalkWorldObjectAction (
        yap::DynamicWorldObject& parent,
        yap::IDialogActor& dialogActor,
        yap::IDialogManager& dialogManager);

      virtual ~TalkWorldObjectAction ();

    protected:

      virtual void HandlePerform ();
  };
} // namespace yse

#endif // YAPOG_SERVER_TALKWORLDOBJECTACTION_HPP
