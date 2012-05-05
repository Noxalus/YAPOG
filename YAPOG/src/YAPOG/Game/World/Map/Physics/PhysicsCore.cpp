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

  PhysicsCore::PhysicsCore (const PhysicsCore& copy)
    : velocity_ (copy.velocity_)
    , minVelocity_ (copy.minVelocity_)
    , maxVelocity_ (copy.maxVelocity_)
    , move_ (copy.move_)
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
    velocity_ = Vector2 (
      velocity.x < 0 ?
      MathHelper::Clamp (velocity.x, -maxVelocity_.x, -minVelocity_.x) :
      MathHelper::Clamp (velocity.x, minVelocity_.x, maxVelocity_.x),
      velocity.y < 0 ?
      MathHelper::Clamp (velocity.y, -maxVelocity_.y, -minVelocity_.y) :
      MathHelper::Clamp (velocity.y, minVelocity_.y, maxVelocity_.y));
  }
} // namespace yap
