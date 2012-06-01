#include "YAPOG/Game/World/Map/Physics/PersistentPhysicsCore.hpp"

namespace yap
{
  PersistentPhysicsCore::PersistentPhysicsCore ()
    : PhysicsCore ()
  {
  }

  PersistentPhysicsCore::~PersistentPhysicsCore ()
  {
  }

  PersistentPhysicsCore::PersistentPhysicsCore (
    const PersistentPhysicsCore& copy)
    : PhysicsCore (copy)
  {
  }

  PersistentPhysicsCore* PersistentPhysicsCore::Clone () const
  {
    return new PersistentPhysicsCore (*this);
  }

  void PersistentPhysicsCore::HandleApplyForce (const Vector2& force)
  {
    SetVelocity (GetVelocity () + force);
  }

  void PersistentPhysicsCore::ResetVelocity (const Time& dt)
  {
  }
} // namespace yap
