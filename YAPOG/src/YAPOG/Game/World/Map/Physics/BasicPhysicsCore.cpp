#include "YAPOG/Game/World/Map/Physics/BasicPhysicsCore.hpp"

namespace yap
{
  const Vector2 BasicPhysicsCore::DEFAULT_MIN_VELOCITY_BOUNDS =
    Vector2 (0.0f, 0.0f);
  const Vector2 BasicPhysicsCore::DEFAULT_MAX_VELOCITY_BOUNDS =
    Vector2 (150.0f, 150.0f);

  BasicPhysicsCore::BasicPhysicsCore ()
    : PhysicsCore ()
  {
    SetVelocityBounds (
      DEFAULT_MIN_VELOCITY_BOUNDS,
      DEFAULT_MAX_VELOCITY_BOUNDS);
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
    SetVelocity (Vector2 ());
  }
} // namespace yap
