#include "YAPOG/Game/World/Map/TalkMapEventAction.hpp"
#include "YAPOG/Game/World/Map/IPlayer.hpp"
#include "YAPOG/Game/World/Map/MapEventArgs.hpp"
#include "YAPOG/Game/World/Map/Physics/MapEventInfo.hpp"
#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"

namespace yap
{
  TalkMapEventAction::TalkMapEventAction ()
    : BaseMapEventAction ()
    , sourceDialogActor_ (nullptr)
  {
  }

  TalkMapEventAction::~TalkMapEventAction ()
  {
  }

  TalkMapEventAction::TalkMapEventAction (const TalkMapEventAction& copy)
    : BaseMapEventAction (copy)
    , sourceDialogActor_ (nullptr)
  {
  }

  TalkMapEventAction* TalkMapEventAction::Clone () const
  {
    return new TalkMapEventAction (*this);
  }

  void TalkMapEventAction::SetSourceDialogActor (IDialogActor& dialogActor)
  {
    sourceDialogActor_ = &dialogActor;
  }

  void TalkMapEventAction::VisitPlayer (IPlayer& visitable)
  {
    BaseMapEventAction::VisitPlayer (visitable);

    switch (GetContextType ())
    {
      case MapEventActionType::In:

        /// @todo Add all conditions (state, facing...)
        if (visitable.HasInputActivated (yap::GameInputType::MapAction))
        {
          visitable.Talk (*sourceDialogActor_);

          GetArgs ().AbortEvents (true);
        }

        break;

      default: break;
    }
  }
} // namespace yap
