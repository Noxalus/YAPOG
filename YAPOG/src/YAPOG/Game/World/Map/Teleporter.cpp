#include "YAPOG/Game/World/Map/Teleporter.hpp"
#include "YAPOG/Game/World/Map/WarpMapEventAction.hpp"
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yap
{
  const int Teleporter::DEFAULT_AREA_Z = 0;
  const int Teleporter::DEFAULT_AREA_H = 1;

  Teleporter::Teleporter (const ID& id)
    : DynamicWorldObject (id)
    , mapWorldID_ ()
    , mapPoint_ ()
    , area_ ()
  {
  }

  Teleporter::~Teleporter ()
  {
  }

  Teleporter::Teleporter (const Teleporter& copy)
    : DynamicWorldObject (copy)
    , mapWorldID_ (copy.mapWorldID_)
    , mapPoint_ (copy.mapPoint_)
    , area_ (copy.area_)
  {
  }

  void Teleporter::Accept (IDynamicWorldObjectVisitor& visitor)
  {
    DynamicWorldObject::Accept (visitor);

    visitor.VisitTeleporter (*this);
  }

  void Teleporter::Accept (IDynamicWorldObjectConstVisitor& visitor) const
  {
    DynamicWorldObject::Accept (visitor);

    visitor.VisitTeleporter (*this);
  }

  const ID& Teleporter::GetMapWorldID () const
  {
    return mapWorldID_;
  }

  const Vector2& Teleporter::GetMapPoint () const
  {
    return mapPoint_;
  }

  const FloatRect& Teleporter::GetArea () const
  {
    return area_;
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
    area_ = area;

    MapEvent* warpEvent = new MapEvent ();

    warpEvent->AddAction (new WarpMapEventAction (mapWorldID_, mapPoint_));

    warpEvent->AddBoundingBox (
      new BoundingBox (
        Vector2 (area_.left, area_.top),
        Vector2 (area_.width, area_.height),
        DEFAULT_AREA_Z,
        DEFAULT_AREA_H));

    AddEvent (warpEvent);
  }
} // namespace yap
