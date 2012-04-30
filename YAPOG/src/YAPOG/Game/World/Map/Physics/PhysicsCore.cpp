#include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/MathHelper.hpp"

namespace yap
{
  PhysicsCore::PhysicsCore ()
    : velocity_ ()
    , minVelocity_ ()
    , maxVelocity_ ()
    , move_ ()
  {
  }

  PhysicsCore::~PhysicsCore ()
  {
  }

  void PhysicsCore::ApplyForce (const Vector2& force)
  {
    HandleApplyForce (force);
  }

  const Vector2& PhysicsCore::GetMove () const
  {
    return move_;
  }

  void PhysicsCore::Update (const Time& dt)
  {
    move_ = velocity_ * dt.GetValue ();

    ResetVelocity (dt);
  }

  void PhysicsCore::SetVelocityBounds (const Vector2& min, const Vector2& max)
  {
    if (max.x < min.x ||
        max.y < min.y)
      throw Exception (
        "[PhysicsCore] Max bound must be greater than min bound.");

    minVelocity_ = min;
    maxVelocity_ = max;
  }

  const Vector2& PhysicsCore::GetVelocity () const
  {
    return velocity_;
  }

  void PhysicsCore::SetVelocity (const Vector2& velocity)
  {
    Vector2 clampedVelocity (
      MathHelper::Clamp (velocity.x, minVelocity_.x, maxVelocity_.x),
      MathHelper::Clamp (velocity.y, minVelocity_.y, maxVelocity_.y));

    velocity_ = clampedVelocity;
  }
} // namespace yap
