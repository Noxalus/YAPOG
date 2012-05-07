#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"

namespace yap
{
  const String DynamicWorldObject::DEFAULT_INACTIVE_STATE = "Inactive";

  DynamicWorldObject::DynamicWorldObject (const ID& id)
    : WorldObject (id)
    , worldID_ ()
    , state_ (DEFAULT_INACTIVE_STATE)
    , physicsCore_ (nullptr)
  {
  }

  DynamicWorldObject::~DynamicWorldObject ()
  {
    delete physicsCore_;
    physicsCore_ = nullptr;
  }

  DynamicWorldObject::DynamicWorldObject (const DynamicWorldObject& copy)
    : WorldObject (copy)
    , worldID_ (copy.worldID_)
    , state_ (copy.state_)
    , physicsCore_ (nullptr)
  {
    if (copy.physicsCore_ != nullptr)
      physicsCore_ = copy.physicsCore_->Clone ();
  }

  const ID& DynamicWorldObject::GetWorldID () const
  {
    return worldID_;
  }

  void DynamicWorldObject::SetWorldID (const ID& id)
  {
    worldID_ = id;
  }

  void DynamicWorldObject::SetPhysicsCore (PhysicsCore* physicsCore)
  {
    physicsCore_ = physicsCore;
  }

  void DynamicWorldObject::ApplyForce (const Vector2& force)
  {
    if (force != Vector2 ())
      TryChangeState ("Moving");

    physicsCore_->ApplyForce (force);
  }

  const Vector2& DynamicWorldObject::GetMove () const
  {
    return physicsCore_->GetMove ();
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

  void DynamicWorldObject::SetState (const String& state)
  {
    state_ = state;

    HandleSetState (state);
  }

  void DynamicWorldObject::Update (const Time& dt)
  {
    HandleUpdate (dt);
  }

  void DynamicWorldObject::HandleUpdate (const Time& dt)
  {
    physicsCore_->Update (dt);
  }

  void DynamicWorldObject::HandleSetState (const String& state)
  {
  }
} // namespace yap
