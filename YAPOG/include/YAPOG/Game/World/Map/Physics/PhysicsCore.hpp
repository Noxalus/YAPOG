#ifndef YAPOG_PHYSICSCORE_HPP
# define YAPOG_PHYSICSCORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class YAPOG_LIB PhysicsCore : public IUpdateable
                              , public ICloneable
  {
      DISALLOW_ASSIGN(PhysicsCore);

    public:

      virtual ~PhysicsCore ();

      void ApplyForce (const Vector2& force);
      const Vector2& GetMove () const;

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual PhysicsCore* Clone () const { return nullptr; };
      /// @}

    protected:

      PhysicsCore ();

      PhysicsCore (const PhysicsCore& copy);

      void SetVelocityBounds (const Vector2& min, const Vector2& max);

      const Vector2& GetVelocity () const;
      void SetVelocity (const Vector2& velocity);

    private:

      virtual void HandleApplyForce (const Vector2& force) = 0;
      virtual void ResetVelocity (const Time& dt) = 0;

      Vector2 velocity_;
      Vector2 minVelocity_;
      Vector2 maxVelocity_;

      Vector2 move_;
  };
} // namespace yap

#endif // YAPOG_PHYSICSCORE_HPP
