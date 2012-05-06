#ifndef YAPOG_WORLDOBJECTPHYSICSINFO_HPP
# define YAPOG_WORLDOBJECTPHYSICSINFO_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class PhysicsCore;

  class YAPOG_LIB WorldObjectPhysicsInfo : public IUpdateable
                                         , public ICloneable
  {
      DISALLOW_ASSIGN(WorldObjectPhysicsInfo);

    public:

      WorldObjectPhysicsInfo ();
      virtual ~WorldObjectPhysicsInfo ();

      void SetCore (PhysicsCore* core);

      void ApplyForce (const Vector2& force);
      const Vector2& GetMove () const;

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      /// @name ICloneable members.
      /// @{
      virtual WorldObjectPhysicsInfo* Clone () const;
      /// @}

    protected:

      WorldObjectPhysicsInfo (const WorldObjectPhysicsInfo& copy);

    private:

      PhysicsCore* core_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTPHYSICSINFO_HPP
