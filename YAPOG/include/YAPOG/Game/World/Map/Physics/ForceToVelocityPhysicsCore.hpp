#ifndef YAPOG_FORCETOVELOCITYPHYSICSCORE_HPP
# define YAPOG_FORCETOVELOCITYPHYSICSCORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"

namespace yap
{
  class YAPOG_LIB ForceToVelocityPhysicsCore : public PhysicsCore
  {
      DISALLOW_ASSIGN(ForceToVelocityPhysicsCore);

    public:

      ForceToVelocityPhysicsCore ();
      virtual ~ForceToVelocityPhysicsCore ();

      virtual ForceToVelocityPhysicsCore* Clone () const;

    protected:

      ForceToVelocityPhysicsCore (const ForceToVelocityPhysicsCore& copy);

    private:

      virtual void HandleApplyForce (const Vector2& force);
      virtual void ResetVelocity (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_FORCETOVELOCITYPHYSICSCORE_HPP
