#ifndef YAPOG_PERSISTENTPHYSICSCORE_HPP
# define YAPOG_PERSISTENTPHYSICSCORE_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/PhysicsCore.hpp"

namespace yap
{
  class PersistentPhysicsCore : public PhysicsCore
  {
      DISALLOW_ASSIGN(PersistentPhysicsCore);

    public:

      PersistentPhysicsCore ();
      virtual ~PersistentPhysicsCore ();

      virtual PersistentPhysicsCore* Clone () const;

    protected:

      PersistentPhysicsCore (const PersistentPhysicsCore& copy);

    private:

      virtual void HandleApplyForce (const Vector2& force);
      virtual void ResetVelocity (const Time& dt);
  };
} // namespace yap

#endif // YAPOG_PERSISTENTPHYSICSCORE_HPP
