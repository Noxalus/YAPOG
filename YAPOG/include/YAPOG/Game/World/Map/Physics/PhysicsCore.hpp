#ifndef YAPOG_PHYSICSCORE_HPP
# define YAPOG_PHYSICSCORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  /// @brief Component on which forces can be applied
  /// that generates a resulting move.
  class YAPOG_LIB PhysicsCore : public IUpdateable
                              , public ICloneable
  {
      DISALLOW_ASSIGN(PhysicsCore);

    public:

      virtual ~PhysicsCore ();

      /// @brief Applies a force on the core.
      /// @param force Force to apply on the core.
      void ApplyForce (const Vector2& force);

      /// @brief Gets the resulting move of this PhysicsCore
      /// from the applied forces on it.
      /// @return The resulting move of this PhysicsCore.
      const Vector2& GetMove () const;

      /// @brief Stores min and max bounds for the velocity of this
      /// PhysicsCore.
      /// @param min Min velocity that this PhysicsCore must have.
      /// @param max Max velocity that this PhysicsCore must have.
      void SetVelocityBounds (const Vector2& min, const Vector2& max);

      /// @brief Forces the value of velocity for this PhysicsCore.
      /// To use to synchronize velocity from server to client.
      void RawSetVelocity (const Vector2& velocity);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual PhysicsCore* Clone () const { return nullptr; }
      /// @}

      /// @name Events.
      /// @{
      Event<const PhysicsCore&, const EmptyEventArgs&> OnStopped;
      Event<const PhysicsCore&, const EmptyEventArgs&> OnMoved;
      Event<const PhysicsCore&,
            const ChangeEventArgs<const Vector2&>&> OnVelocityChanged;
      /// @}

    protected:

      PhysicsCore ();

      PhysicsCore (const PhysicsCore& copy);

      const Vector2& GetVelocity () const;
      void SetVelocity (const Vector2& velocity);

      /// @brief Reset velocity value with @a velocity.
      /// To use in ResetVelocity (const Time&).
      /// Does not call OnVelocityChanged event.
      /// @param velocity Value to change current velocity with.
      void ResetVelocity (const Vector2& velocity);

    private:

      void BoundVelocity (const Vector2& velocity, Vector2& result);

      virtual void HandleApplyForce (const Vector2& force) = 0;
      virtual void ResetVelocity (const Time& dt) = 0;

      Vector2 velocity_;
      Vector2 lastVelocity_;
      Vector2 minVelocity_;
      Vector2 maxVelocity_;

      Vector2 move_;
  };
} // namespace yap

#endif // YAPOG_PHYSICSCORE_HPP
