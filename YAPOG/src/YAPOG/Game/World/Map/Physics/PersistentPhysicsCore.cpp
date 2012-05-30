#include "YAPOG/Game/World/Map/Physics/PersistentPhysicsCore.hpp"

namespace yap
{
  const Vector2 PersistentPhysicsCore::DEFAULT_MIN_VELOCITY_BOUNDS =
    Vector2 (0.0f, 0.0f);
  const Vector2 PersistentPhysicsCore::DEFAULT_MAX_VELOCITY_BOUNDS =
    Vector2 (150.0f, 150.0f);

  PersistentPhysicsCore::PersistentPhysicsCore ()
    : PhysicsCore ()
  {
    SetVelocityBounds (
      DEFAULT_MIN_VELOCITY_BOUNDS,
      DEFAULT_MAX_VELOCITY_BOUNDS);
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
