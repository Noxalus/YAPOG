#include "YAPOG/Game/World/Map/DestructibleObject.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/DestroyObjectMapEventAction.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"

namespace yap
{
  const String DestructibleObject::OBJECT_FACTORY_TYPE_NAME =
    "DestructibleObject";

  DestructibleObject::DestructibleObject (const ID& id)
    : DynamicWorldObject (id)
    , destructionBox_ (nullptr)
    , destructionEventAction_ (nullptr)
  {
  }

  DestructibleObject::~DestructibleObject ()
  {
  }

  DestructibleObject::DestructibleObject (const DestructibleObject& copy)
    : DynamicWorldObject (copy)
    , destructionBox_ (nullptr)
    , destructionEventAction_ (nullptr)
  {
    SetDestructionBox (new BoundingBox (*copy.destructionBox_));
  }

  DestructibleObject* DestructibleObject::Clone () const
  {
    return new DestructibleObject (*this);
  }

  void DestructibleObject::Accept (IDynamicWorldObjectVisitor& visitor)
  {
    DynamicWorldObject::Accept (visitor);

    visitor.VisitDestructibleObject (*this);
  }

  void DestructibleObject::Accept (
    IDynamicWorldObjectConstVisitor& visitor) const
  {
    DynamicWorldObject::Accept (visitor);

    visitor.VisitDestructibleObject (*this);
  }

  void DestructibleObject::SetDestructionBox (BoundingBox* destructionBox)
  {
    destructionBox_ = destructionBox;

    MapEvent* destructionEvent = new MapEvent ();

    destructionEventAction_ = new DestroyObjectMapEventAction ();
    destructionEvent->AddAction (destructionEventAction_);

    destructionEvent->AddBoundingBox (destructionBox_);

    AddEvent (destructionEvent);
  }

  void DestructibleObject::HandleSetWorldID (const ID& worldID)
  {
    DynamicWorldObject::HandleSetWorldID (worldID);

    destructionEventAction_->SetTargetWorldID (worldID);
  }

  const String& DestructibleObject::GetObjectFactoryTypeName () const
  {
    return OBJECT_FACTORY_TYPE_NAME;
  }
} // namespace yap
