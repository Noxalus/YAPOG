#include "YAPOG/Game/World/Map/Physics/ForceToVelocityPhysicsCore.hpp"

namespace yap
{
  ForceToVelocityPhysicsCore::ForceToVelocityPhysicsCore ()
    : PhysicsCore ()
  {
  }

  ForceToVelocityPhysicsCore::~ForceToVelocityPhysicsCore ()
  {
  }

  ForceToVelocityPhysicsCore::ForceToVelocityPhysicsCore (
    const ForceToVelocityPhysicsCore& copy)
    : PhysicsCore (copy)
  {
  }

  ForceToVelocityPhysicsCore* ForceToVelocityPhysicsCore::Clone () const
  {
    return new ForceToVelocityPhysicsCore (*this);
  }

  void ForceToVelocityPhysicsCore::HandleApplyForce (const Vector2& force)
  {
    SetVelocity (force);
  }

  void ForceToVelocityPhysicsCore::ResetVelocity (const Time& dt)
  {
  }
} // namespace yap
