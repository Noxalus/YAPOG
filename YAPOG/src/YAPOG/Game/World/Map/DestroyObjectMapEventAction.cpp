#include "YAPOG/Game/World/Map/DestroyObjectMapEventAction.hpp"
#include "YAPOG/Game/World/Map/IPlayer.hpp"
#include "YAPOG/Game/World/Map/MapEventArgs.hpp"

namespace yap
{
  DestroyObjectMapEventAction::DestroyObjectMapEventAction (
    MapEventActionType type)
    : BaseMapEventAction (type)
    , targetWorldID_ ()
  {
  }

  DestroyObjectMapEventAction::~DestroyObjectMapEventAction ()
  {
  }

  DestroyObjectMapEventAction::DestroyObjectMapEventAction (
    const DestroyObjectMapEventAction& copy)
    : BaseMapEventAction (copy)
    , targetWorldID_ (copy.targetWorldID_)
  {
  }

  DestroyObjectMapEventAction* DestroyObjectMapEventAction::Clone () const
  {
    return new DestroyObjectMapEventAction (*this);
  }

  void DestroyObjectMapEventAction::SetTargetWorldID (const ID& targetWorldID)
  {
    targetWorldID_ = targetWorldID;
  }

  void DestroyObjectMapEventAction::VisitPlayer (IPlayer& visitable)
  {
    BaseMapEventAction::VisitPlayer (visitable);

    /// @todo Make `GameInputIsActivatedMapEventCondition' class.
    if (visitable.HasInput (GameInputType::MapAction))
    {
      visitable.DestroyObject (targetWorldID_);
      GetArgs ().AbortEvents (true);
    }
  }
} // namespace yap
