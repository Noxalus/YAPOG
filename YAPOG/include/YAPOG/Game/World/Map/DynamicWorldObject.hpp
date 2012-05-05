#ifndef YAPOG_DYNAMICWORLDOBJECT_HPP
# define YAPOG_DYNAMICWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObject.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/World/Map/WorldObjectState.hpp"

namespace yap
{
  class WorldObjectPhysicsInfo;
  class PhysicsCore;

  class YAPOG_LIB DynamicWorldObject : public WorldObject
                                     , public IUpdateable
  {
      DISALLOW_ASSIGN(DynamicWorldObject);

    public:

      virtual ~DynamicWorldObject ();

      const ID& GetWorldID () const;
      void SetWorldID (const ID& id);

      void SetPhysicsCore (PhysicsCore* physicsCore);
      void ApplyForce (const Vector2& force);
      const Vector2& GetMove () const;

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      explicit DynamicWorldObject (const ID& id);

      DynamicWorldObject (const DynamicWorldObject& copy);

      void SetPhysicsInfo (WorldObjectPhysicsInfo* physicsInfo);

      virtual void HandleUpdate (const Time& dt);

    private:

      virtual void InitPhysicsInfo ();

      ID worldID_;

      WorldObjectState state_;

      WorldObjectPhysicsInfo* physicsInfo_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECT_HPP
