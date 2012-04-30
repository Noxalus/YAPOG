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

  class DynamicWorldObject : public WorldObject
                           , public IUpdateable
  {
      DISALLOW_ASSIGN(DynamicWorldObject);

    public:

      virtual ~DynamicWorldObject ();

      const ID& GetWorldID () const;
      void SetWorldID (const ID& id);

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

    protected:

      explicit DynamicWorldObject (const ID& id);

      DynamicWorldObject (const DynamicWorldObject& copy);

      void SetPhysicsInfo (WorldObjectPhysicsInfo* physicsInfo);

    private:

      virtual void HandleUpdate (const Time& dt);

      virtual WorldObjectPhysicsInfo& GetPhysicsInfo () = 0;

      ID worldID_;

      WorldObjectState state_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECT_HPP
