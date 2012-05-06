#include "YAPOG/Game/World/Map/WorldObjectPhysicsInfo.hpp"
#include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"

namespace yap
{
  WorldObjectPhysicsInfo::WorldObjectPhysicsInfo ()
    : core_ (nullptr)
  {
  }

  WorldObjectPhysicsInfo::~WorldObjectPhysicsInfo ()
  {
    delete core_;
    core_ = nullptr;
  }

  WorldObjectPhysicsInfo::WorldObjectPhysicsInfo (
    const WorldObjectPhysicsInfo& copy)
    : core_ (copy.core_->Clone ())
  {
  }

  WorldObjectPhysicsInfo* WorldObjectPhysicsInfo::Clone () const
  {
    return new WorldObjectPhysicsInfo (*this);
  }

  void WorldObjectPhysicsInfo::SetCore (PhysicsCore* core)
  {
    core_ = core;
  }

  void WorldObjectPhysicsInfo::ApplyForce (const Vector2& force)
  {
    core_->ApplyForce (force);
  }

  const Vector2& WorldObjectPhysicsInfo::GetMove () const
  {
    return core_->GetMove ();
  }

  void WorldObjectPhysicsInfo::Update (const Time& dt)
  {
    core_->Update (dt);
  }
} // namespace yap
