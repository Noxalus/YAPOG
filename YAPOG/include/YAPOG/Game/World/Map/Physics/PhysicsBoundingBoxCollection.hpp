#ifndef YAPOG_PHYSICSBOUNDINGBOXCOLLECTION_HPP
# define YAPOG_PHYSICSBOUNDINGBOXCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/BoundingBoxCollection.hpp"
# include "YAPOG/Game/World/Map/Physics/MapCollidableInfo.hpp"

namespace yap
{
  class WorldObject;

  class YAPOG_LIB PhysicsBoundingBoxCollection : public BoundingBoxCollection
  {
      DISALLOW_ASSIGN(PhysicsBoundingBoxCollection);

    public:

      PhysicsBoundingBoxCollection ();
      virtual ~PhysicsBoundingBoxCollection ();

      PhysicsBoundingBoxCollection (const PhysicsBoundingBoxCollection& copy);

      void AddPhysicsBoundingBox (BoundingBox* boundingBox);
      void RemovePhysicsBoundingBox (BoundingBox* boundingBox);

      void SetCollidableArea (
        const WorldObject& parent,
        CollidableArea* collidableArea);

      bool CollidesWithArea (
        const CollidableArea& collidableArea,
        const Vector2& offset) const;

    private:

      virtual void HandleAddBoundingBoxToCollidableArea (
        BoundingBox* boundingBox);
      virtual void HandleRemoveBoundingBoxFromCollidableArea (
        BoundingBox* boundingBox);

      const WorldObject* parent_;
  };
} // namespace yap

#endif // YAPOG_PHYSICSBOUNDINGBOXCOLLECTION_HPP
