#include "YAPOG/Game/World/Map/WarpMapEventAction.hpp"
#include "YAPOG/Game/World/Map/IPlayer.hpp"

namespace yap
{
  WarpMapEventAction::WarpMapEventAction (
    MapEventActionType type,
    const ID& mapWorldID,
    const Vector2& point)
    : BaseMapEventAction (type)
    , mapWorldID_ (mapWorldID)
    , point_ (point)
  {
  }

  WarpMapEventAction::~WarpMapEventAction ()
  {
  }

  void WarpMapEventAction::VisitPlayer (IPlayer& visitable)
  {
    visitable.Warp (mapWorldID_, point_);
  }
} // namespace yap
