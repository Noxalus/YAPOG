#ifndef YAPOG_BASICPHYSICSCORE_HPP
# define YAPOG_BASICPHYSICSCORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"

namespace yap
{
  class YAPOG_LIB BasicPhysicsCore : public PhysicsCore
  {
      DISALLOW_ASSIGN(BasicPhysicsCore);

    public:

      BasicPhysicsCore ();
      virtual ~BasicPhysicsCore ();

      virtual BasicPhysicsCore* Clone () const;

    protected:

      BasicPhysicsCore (const BasicPhysicsCore& copy);

    private:

      virtual void HandleApplyForce (const Vector2& force);
      virtual void ResetVelocity (const Time& dt);

      static const Vector2 DEFAULT_MIN_VELOCITY_BOUNDS;
      static const Vector2 DEFAULT_MAX_VELOCITY_BOUNDS;
  };
} // namespace yap

#endif // YAPOG_BASICPHYSICSCORE_HPP
