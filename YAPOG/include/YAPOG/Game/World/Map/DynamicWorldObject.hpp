#ifndef YAPOG_DYNAMICWORLDOBJECT_HPP
# define YAPOG_DYNAMICWORLDOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/WorldObject.hpp"
# include "YAPOG/Game/IUpdateable.hpp"
# include "YAPOG/Game/ID.hpp"
# include "YAPOG/Game/World/Map/WorldObjectState.hpp"
# include "YAPOG/System/Event/Event.hpp"

namespace yap
{
  struct IDynamicWorldObjectVisitor;
  struct IDynamicWorldObjectConstVisitor;

  class PhysicsCore;

  class YAPOG_LIB DynamicWorldObject : public WorldObject
                                     , public IUpdateable
  {
      DISALLOW_ASSIGN(DynamicWorldObject);

    public:

      virtual ~DynamicWorldObject ();

      virtual void Accept (IDynamicWorldObjectVisitor& visitor) = 0;
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const = 0;

      const ID& GetWorldID () const;
      void SetWorldID (const ID& id);

      /// @brief Returns the ID of this type from the ObjectFactory.
      const ID& GetTypeID () const;

      const Vector2& GetMaxVelocity () const;
      void SetMaxVelocity (const Vector2& maxVelocity);

      void SetPhysicsCore (PhysicsCore* physicsCore);
      void ApplyForce (const Vector2& force);
      const Vector2& GetMove () const;

      const String& GetState () const;
      const String& GetLogicalState () const;
      bool TryChangeState (const String& state);
      void SetInactive ();

      bool IsActive () const;

      bool IsMoving () const;

      /// @name IUpdateable members.
      /// @{
      virtual void Update (const Time& dt);
      /// @}

      /// @name Events.
      /// @{
      Event<DynamicWorldObject&,
            const ChangeEventArgs<const Vector2&>&> OnVelocityChanged;
      Event<DynamicWorldObject&, const String&> OnStateChanged;
      /// @}

    protected:

      explicit DynamicWorldObject (const ID& id);

      DynamicWorldObject (const DynamicWorldObject& copy);

      virtual const String& GetObjectFactoryTypeName () const = 0;

      virtual void HandleUpdate (const Time& dt);
      virtual void HandleSetState (const String& state);

      virtual void HandleMove (const Vector2& offset);

    private:

      void SetState (const String& state);

      static const String DEFAULT_INACTIVE_STATE;
      static const Vector2 DEFAULT_MAX_VELOCITY;

      ID worldID_;

      WorldObjectState state_;

      PhysicsCore* physicsCore_;
      Vector2 maxVelocity_;
  };
} // namespace yap

#endif // YAPOG_DYNAMICWORLDOBJECT_HPP
