#include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
#include "YAPOG/Game/World/Map/WorldObjectPhysicsInfo.hpp"

namespace yap
{
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
} // namespace yap
