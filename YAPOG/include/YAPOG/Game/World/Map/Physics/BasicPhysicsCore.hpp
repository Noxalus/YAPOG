#ifndef YAPOG_BASICPHYSICSCORE_HPP
# define YAPOG_BASICPHYSICSCORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"

namespace yap
{
  class BasicPhysicsCore : public PhysicsCore
  {
      DISALLOW_COPY(BasicPhysicsCore);

    public:

      BasicPhysicsCore ();
      virtual ~BasicPhysicsCore ();

    private:

      virtual void HandleApplyForce (const Vector2& force);
      virtual void ResetVelocity (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_BASICPHYSICSCORE_HPP
