#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"
#include "YAPOG/Game/World/Map/Physics/BoundingBox.hpp"
#include "YAPOG/Game/Factory/ObjectFactory.hpp"
#include "YAPOG/Game/World/Map/MapEvent.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
#include "YAPOG/Game/World/Map/IDynamicWorldObjectConstVisitor.hpp"

namespace yap
{
  const String DynamicWorldObject::DEFAULT_INACTIVE_STATE = "Inactive";
  const Vector2 DynamicWorldObject::DEFAULT_MAX_VELOCITY =
    Vector2 (150.0f, 150.0f);

  DynamicWorldObject::DynamicWorldObject (const ID& id)
    : WorldObject (id)
    , OnMoved ()
    , OnVelocityChanged ()
    , OnStateChanged ()
    , worldID_ ()
    , state_ (DEFAULT_INACTIVE_STATE)
    , physicsCore_ (nullptr)
    , maxVelocity_ (DEFAULT_MAX_VELOCITY)
    , events_ ()
    , triggerBoundingBoxes_ ()
    , sourceBoundingBoxes_ ()
  {
  }

  DynamicWorldObject::~DynamicWorldObject ()
  {
    delete physicsCore_;
    physicsCore_ = nullptr;
  }

  DynamicWorldObject::DynamicWorldObject (const DynamicWorldObject& copy)
    : WorldObject (copy)
    , OnMoved ()
    , OnVelocityChanged ()
    , OnStateChanged ()
    , worldID_ (copy.worldID_)
    , state_ (copy.state_)
    , physicsCore_ (nullptr)
    , maxVelocity_ (copy.maxVelocity_)
    , events_ ()
    , triggerBoundingBoxes_ (copy.triggerBoundingBoxes_)
    , sourceBoundingBoxes_ (copy.sourceBoundingBoxes_)
  {
    if (copy.physicsCore_ != nullptr)
      SetPhysicsCore (copy.physicsCore_->Clone ());
  }

  void DynamicWorldObject::Accept (IDynamicWorldObjectVisitor& visitor)
  {
    visitor.VisitDynamicWorldObject (*this);
  }

  void DynamicWorldObject::Accept (
    IDynamicWorldObjectConstVisitor& visitor) const
  {
    visitor.VisitDynamicWorldObject (*this);
  }

  const ID& DynamicWorldObject::GetWorldID () const
  {
    return worldID_;
  }

  void DynamicWorldObject::SetWorldID (const ID& id)
  {
    worldID_ = id;

    HandleSetWorldID (id);
  }

  const ID& DynamicWorldObject::GetTypeID () const
  {
    return ObjectFactory::Instance ().GetID (GetObjectFactoryTypeName ());
  }

  const Vector2& DynamicWorldObject::GetMaxVelocity () const
  {
    return maxVelocity_;
  }

  void DynamicWorldObject::SetMaxVelocity (const Vector2& maxVelocity)
  {
    maxVelocity_ = maxVelocity;
  }

  void DynamicWorldObject::SetPhysicsCore (PhysicsCore* physicsCore)
  {
    if (physicsCore_ == physicsCore)
      return;

    delete physicsCore_;

    physicsCore_ = physicsCore;

    physicsCore_->OnMoved +=
      [this] (const PhysicsCore& sender, const EmptyEventArgs& args)
    {
      TryChangeState ("Moving");
    };

    physicsCore_->OnStopped +=
      [this] (const PhysicsCore& sender, const EmptyEventArgs& args)
    {
      SetInactive ();
    };

    physicsCore_->OnVelocityChanged +=
      [this] (const PhysicsCore& sender,
              const ChangeEventArgs<const Vector2&>& args)
    {
      HandleOnVelocityChanged (args.Old, args.Current);
    };
  }

  void DynamicWorldObject::ApplyForce (const Vector2& force)
  {
    physicsCore_->ApplyForce (force);

    HandleApplyForce (force);
  }

  const Vector2& DynamicWorldObject::GetMove () const
  {
    return physicsCore_->GetMove ();
  }

  void DynamicWorldObject::RawSetVelocity (const Vector2& velocity)
  {
    physicsCore_->RawSetVelocity (velocity);
  }

  bool DynamicWorldObject::IsActive () const
  {
    return GetLogicalState () != DEFAULT_INACTIVE_STATE;
  }

  const String& DynamicWorldObject::GetState () const
  {
    return state_.GetName ();
  }

  const String& DynamicWorldObject::GetLogicalState () const
  {
    return state_.GetLogicalName ();
  }

  bool DynamicWorldObject::TryChangeState (const String& state)
  {
    if (IsActive ())
    {
      if (state_.IsJoinedTo (state))
      {
        SetState (state);
        return true;
      }

      if (state != DEFAULT_INACTIVE_STATE)
        return GetState () == state;

      SetInactive ();

      return true;
    }

    SetState (state);

    return true;
  }

  void DynamicWorldObject::SetInactive ()
  {
    SetState (DEFAULT_INACTIVE_STATE);
  }

  void DynamicWorldObject::RawSetState (const String& state)
  {
    SetState (state);
  }

  void DynamicWorldObject::SetState (const String& state)
  {
    const String& oldState = state_.GetName ();

    state_ = state;

    OnStateChanged (
      *this, ChangeEventArgs<const String&> (
        oldState,
        state_.GetName ()));

    HandleSetState (state);
  }

  bool DynamicWorldObject::IsMoving () const
  {
    return GetLogicalState () == "Moving";
  }

  void DynamicWorldObject::AddTriggerBoundingBox (BoundingBox* boundingBox)
  {
    AdjustCollidablePosition (*boundingBox);

    triggerBoundingBoxes_.AddEventTriggerBoundingBox (boundingBox);
  }

  void DynamicWorldObject::AddEvent (MapEvent* event)
  {
    events_.Add (event);

    event->AddToEventBoundingBoxCollection (sourceBoundingBoxes_, *this);
  }

  void DynamicWorldObject::RemoveEvent (MapEvent* event)
  {
    events_.Remove (event);

    event->RemoveFromEventBoundingBoxCollection (sourceBoundingBoxes_);
  }

  void DynamicWorldObject::GetEventsCollidingWith (
    const CollidableArea& collidableArea,
    MapEventQueue& events) const
  {
    triggerBoundingBoxes_.GetEventsCollidingWith (collidableArea, events);
  }

  void DynamicWorldObject::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void DynamicWorldObject::HandleSetWorldID (const ID& worldID)
  {
  }

  void DynamicWorldObject::HandleSetCollidableArea (
    CollidableArea* collidableArea)
  {
    WorldObject::HandleSetCollidableArea (collidableArea);

    triggerBoundingBoxes_.SetCollidableArea (*this, collidableArea);
    sourceBoundingBoxes_.SetCollidableArea (*this, collidableArea);
  }

  void DynamicWorldObject::HandleApplyForce (const Vector2& force)
  {
  }

  void DynamicWorldObject::HandleUpdate (const Time& dt)
  {
    physicsCore_->Update (dt);
  }

  void DynamicWorldObject::HandleSetState (const String& state)
  {
  }

  void DynamicWorldObject::HandleMove (const Vector2& offset)
  {
    WorldObject::HandleMove (offset);

    triggerBoundingBoxes_.Move (offset);
    sourceBoundingBoxes_.Move (offset);

    OnMoved (*this, offset);
  }

  void DynamicWorldObject::HandleScale (const Vector2& factor)
  {
    WorldObject::HandleScale (factor);

    triggerBoundingBoxes_.Scale (factor);
    sourceBoundingBoxes_.Scale (factor);
  }

  void DynamicWorldObject::HandleSetZ (int z)
  {
    WorldObject::HandleSetZ (z);

    triggerBoundingBoxes_.SetZ (z);
    sourceBoundingBoxes_.SetZ (z);
  }

  void DynamicWorldObject::HandleSetH (int h)
  {
    WorldObject::HandleSetH (h);

    triggerBoundingBoxes_.SetH (h);
    sourceBoundingBoxes_.SetH (h);
  }

  void DynamicWorldObject::HandleOnVelocityChanged (
    const Vector2& oldVelocity,
    const Vector2& currentVelocity)
  {
    OnVelocityChanged (
      *this,
      ChangeEventArgs<const Vector2&> (
        oldVelocity,
        currentVelocity));
  }
} // namespace yap
