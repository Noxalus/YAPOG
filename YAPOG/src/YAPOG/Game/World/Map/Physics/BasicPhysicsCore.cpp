#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"

namespace yap
{
  BasicPhysicsCore::BasicPhysicsCore ()
    : PhysicsCore ()
  {
  }

  BasicPhysicsCore::~BasicPhysicsCore ()
  {
  }

  BasicPhysicsCore::BasicPhysicsCore (const BasicPhysicsCore& copy)
    : PhysicsCore (copy)
  {
  }

  BasicPhysicsCore* BasicPhysicsCore::Clone () const
  {
    return new BasicPhysicsCore (*this);
  }

  void BasicPhysicsCore::HandleApplyForce (const Vector2& force)
  {
    SetVelocity (GetVelocity () + force);
  }

  void BasicPhysicsCore::ResetVelocity (const Time& dt)
  {
    PhysicsCore::ResetVelocity (Vector2 ());
  }
} // namespace yap
