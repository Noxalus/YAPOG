#include "YAPOG/Game/World/Map/Teleporter.hpp"
#include "YAPOG/Game/World/Map/WarpMapEventAction.hpp"
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  Teleporter::Teleporter (const ID& id)
    : DynamicWorldObject (id)
    , mapWorldID_ ()
    , mapPoint_ ()
  {
  }

  Teleporter::~Teleporter ()
  {
  }

  Teleporter::Teleporter (const Teleporter& copy)
    : DynamicWorldObject (copy)
    , mapWorldID_ (copy.mapWorldID_)
    , mapPoint_ (copy.mapPoint_)
  {
  }

  void Teleporter::Accept (IDynamicWorldObjectVisitor& visitor)
  {
    visitor.VisitTeleporter (*this);
  }

  void Teleporter::Accept (IDynamicWorldObjectConstVisitor& visitor) const
  {
    visitor.VisitTeleporter (*this);
  }

  void Teleporter::SetMapWorldID (const ID& mapWorldID)
  {
    mapWorldID_ = mapWorldID;
  }

  void Teleporter::SetMapPoint (const Vector2& mapPoint)
  {
    mapPoint_ = mapPoint;
  }

  void Teleporter::SetArea (const FloatRect& area)
  {
    MapEvent* warpEvent = new MapEvent ();
    WarpMapEventAction* warpAction = new WarpMapEventAction (
      MapEventActionType::Enter,
      mapWorldID_,
      mapPoint_);

    warpEvent->AddAction (warpAction);
    AddEvent (warpEvent);
  }
} // namespace yap
