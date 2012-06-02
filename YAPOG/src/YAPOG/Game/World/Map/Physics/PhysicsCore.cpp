#include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/MathHelper.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const Vector2 PhysicsCore::DEFAULT_MIN_VELOCITY_BOUNDS =
    Vector2 (0.0f, 0.0f);
  const Vector2 PhysicsCore::DEFAULT_MAX_VELOCITY_BOUNDS =
    Vector2 (150.0f, 150.0f);

  PhysicsCore::PhysicsCore ()
    : OnStopped ()
    , OnMoved ()
    , OnVelocityChanged ()
    , velocity_ ()
    , lastVelocity_ ()
    , minVelocity_ (DEFAULT_MIN_VELOCITY_BOUNDS)
    , maxVelocity_ (DEFAULT_MAX_VELOCITY_BOUNDS)
    , move_ ()
  {
  }

  PhysicsCore::~PhysicsCore ()
  {
  }

  PhysicsCore::PhysicsCore (const PhysicsCore& copy)
    : OnStopped ()
    , OnMoved ()
    , OnVelocityChanged ()
    , velocity_ (copy.velocity_)
    , lastVelocity_ (copy.lastVelocity_)
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
    Vector2 oldMove = move_;

    move_ = velocity_ * dt.GetValue ();

    ResetVelocity (dt);

    if (move_ == oldMove)
      return;

    if (oldMove == Vector2 (0.0f, 0.0f))
      OnMoved (*this, EmptyEventArgs ());
    else if (move_ == Vector2 (0.0f, 0.0f))
      OnStopped (*this, EmptyEventArgs ());
  }

  void PhysicsCore::SetVelocityBounds (const Vector2& min, const Vector2& max)
  {
    if (max.x < min.x ||
        max.y < min.y)
      YAPOG_THROW("[PhysicsCore] Max bound must be greater than min bound.");

    minVelocity_ = min;
    maxVelocity_ = max;
  }

  void PhysicsCore::RawSetVelocity (const Vector2& velocity)
  {
    SetVelocity (velocity);
  }

  const Vector2& PhysicsCore::GetVelocity () const
  {
    return velocity_;
  }

  void PhysicsCore::SetVelocity (const Vector2& velocity)
  {
    if (velocity == velocity_)
    {
      if (velocity != lastVelocity_)
        OnVelocityChanged (
          *this,
          ChangeEventArgs<const Vector2&> (
            lastVelocity_,
            velocity_));

      return;
    }

    BoundVelocity (velocity, velocity_);

    if (velocity_ == lastVelocity_)
      return;

    OnVelocityChanged (
      *this,
      ChangeEventArgs<const Vector2&> (
        lastVelocity_,
        velocity_));
  }

  void PhysicsCore::ResetVelocity (const Vector2& velocity)
  {
    lastVelocity_ = velocity_;

    BoundVelocity (velocity, velocity_);
  }

  void PhysicsCore::BoundVelocity (const Vector2& velocity, Vector2& result)
  {
    result = Vector2 (
      velocity.x < 0 ?
      MathHelper::Clamp (velocity.x, -maxVelocity_.x, -minVelocity_.x) :
      MathHelper::Clamp (velocity.x, minVelocity_.x, maxVelocity_.x),
      velocity.y < 0 ?
      MathHelper::Clamp (velocity.y, -maxVelocity_.y, -minVelocity_.y) :
      MathHelper::Clamp (velocity.y, minVelocity_.y, maxVelocity_.y));
  }
} // namespace yap
