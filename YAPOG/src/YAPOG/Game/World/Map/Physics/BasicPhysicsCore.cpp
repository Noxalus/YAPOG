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

  void BasicPhysicsCore::HandleApplyForce (const Vector2& force)
  {
    SetVelocity (GetVelocity () + force);
  }

  void BasicPhysicsCore::ResetVelocity (const Time& dt)
  {
    SetVelocity (Vector2 ());
  }
} // namespace yap
