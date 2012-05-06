#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/WorldObjectPhysicsInfo.hpp"

namespace yap
{
  const String DynamicWorldObject::DEFAULT_INACTIVE_STATE = "Inactive";

  DynamicWorldObject::DynamicWorldObject (const ID& id)
    : WorldObject (id)
    , worldID_ ()
    , state_ ()
    , physicsInfo_ (nullptr)
  {
  }

  DynamicWorldObject::~DynamicWorldObject ()
  {
    delete physicsInfo_;
    physicsInfo_ = nullptr;
  }

  DynamicWorldObject::DynamicWorldObject (const DynamicWorldObject& copy)
    : WorldObject (copy)
    , worldID_ (copy.worldID_)
    , state_ (copy.state_)
    , physicsInfo_ (nullptr)
  {
    if (copy.physicsInfo_ != nullptr)
      physicsInfo_ = copy.physicsInfo_->Clone ();
  }

  const ID& DynamicWorldObject::GetWorldID () const
  {
    return worldID_;
  }

  void DynamicWorldObject::SetWorldID (const ID& id)
  {
    worldID_ = id;
  }

  void DynamicWorldObject::InitPhysicsInfo ()
  {
    physicsInfo_ = new WorldObjectPhysicsInfo ();
  }

  void DynamicWorldObject::SetPhysicsCore (PhysicsCore* physicsCore)
  {
    if (physicsInfo_ != nullptr)
      return;

    InitPhysicsInfo ();

    physicsInfo_->SetCore (physicsCore);
  }

  void DynamicWorldObject::ApplyForce (const Vector2& force)
  {
    physicsInfo_->ApplyForce (force);
  }

  const Vector2& DynamicWorldObject::GetMove () const
  {
    return physicsInfo_->GetMove ();
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

  void DynamicWorldObject::SetPhysicsInfo (WorldObjectPhysicsInfo* physicsInfo)
  {
    physicsInfo_ = physicsInfo;
  }

  void DynamicWorldObject::HandleUpdate (const Time& dt)
  {
    physicsInfo_->Update (dt);
  }

  void DynamicWorldObject::HandleSetState (const String& state)
  {
  }
} // namespace yap
