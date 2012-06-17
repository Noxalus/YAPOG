#include "YAPOG/Game/World/Map/DestroyObjectMapEventAction.hpp"
#include "YAPOG/Game/World/Map/IPlayer.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
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

    DebugLogger::Instance ().LogLine ("DESTROY!");

    if (visitable.HasInput (GameInputType::MapAction))
    {
      DebugLogger::Instance ().LogLine ("DESTROYeeeeeeeeeeeeeeeeeeeeeeeeeed!");
      visitable.DestroyObject (targetWorldID_);
    }
  }
} // namespace yap
