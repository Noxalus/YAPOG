#include "YAPOG/Game/World/Map/WarpMapEventAction.hpp"
#include "YAPOG/Game/World/Map/IPlayer.hpp"
#include "YAPOG/Game/World/Map/MapEventArgs.hpp"

#include "YAPOG/System/IO/Log/DebugLogger.hpp"
namespace yap
{
  WarpMapEventAction::WarpMapEventAction (
    const ID& mapWorldID,
    const Vector2& mapPoint)
    : BaseMapEventAction ()
    , mapWorldID_ (mapWorldID)
    , mapPoint_ (mapPoint)
  {
  }

  WarpMapEventAction::~WarpMapEventAction ()
  {
  }

  WarpMapEventAction::WarpMapEventAction (const WarpMapEventAction& copy)
    : BaseMapEventAction (copy)
    , mapWorldID_ (copy.mapWorldID_)
    , mapPoint_ (copy.mapPoint_)
  {
  }

  WarpMapEventAction* WarpMapEventAction::Clone () const
  {
    return new WarpMapEventAction (*this);
  }

  void WarpMapEventAction::VisitPlayer (IPlayer& visitable)
  {
    switch (GetContextType ())
    {
      case MapEventActionType::Enter:

        GetArgs ().AbortEvents (true);
        visitable.Warp (mapWorldID_, mapPoint_);

        break;

      default: break;
    }
  }
} // namespace yap
