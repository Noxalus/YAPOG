#ifndef YAPOG_DESTRUCTIBLEOBJECT_HPP
# define YAPOG_DESTRUCTIBLEOBJECT_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/DynamicWorldObject.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class DestroyObjectMapEventAction;

  class YAPOG_LIB DestructibleObject : public DynamicWorldObject
  {
      DISALLOW_ASSIGN(DestructibleObject);

    public:

      explicit DestructibleObject (const ID& id);
      virtual ~DestructibleObject ();

      virtual void Accept (IDynamicWorldObjectVisitor& visitor);
      virtual void Accept (IDynamicWorldObjectConstVisitor& visitor) const;

      void SetDestructionBox (BoundingBox* destructionBox);

      /// @name ICloneable members.
      /// @{
      virtual DestructibleObject* Clone () const;
      /// @}

    protected:

      DestructibleObject (const DestructibleObject& copy);

      virtual void HandleSetWorldID (const ID& worldID);

      virtual const String& GetObjectFactoryTypeName () const;

    private:

      static const String OBJECT_FACTORY_TYPE_NAME;

      BoundingBox* destructionBox_;
      DestroyObjectMapEventAction* destructionEventAction_;
  };
} // namespace yap

#endif // YAPOG_DESTRUCTIBLEOBJECT_HPP
