#ifndef YAPOG_BOUNDINGBOXCOLLECTION_HPP
# define YAPOG_BOUNDINGBOXCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/ICollidable.hpp"
# include "YAPOG/Game/World/Spatial3Info.hpp"
# include "YAPOG/Collection/List.hpp"

namespace yap
{
  class BoundingBox;
  class CollidableArea;
  class WorldObject;

  class YAPOG_LIB BoundingBoxCollection : public ICollidable
  {
      DISALLOW_ASSIGN(BoundingBoxCollection);

    public:

      typedef collection::List<BoundingBox*>::ItType ItType;
      typedef collection::List<BoundingBox*>::ConstItType ConstItType;

      virtual ~BoundingBoxCollection ();

      ItType begin ();
      ConstItType begin () const;
      ItType end ();
      ConstItType end () const;

      /// @name ISpatial members.
      /// @{
      virtual const Vector2& GetPosition () const;
      virtual const Vector2& GetSize () const;

      virtual const Vector2& GetTopLeft () const;
      virtual const Vector2& GetBottomRight () const;
      virtual const Vector2& GetCenter () const;

      virtual const FloatRect& GetRectangle () const;

      virtual void Move (const Vector2& offset);
      virtual void Scale (const Vector2& factor);

      virtual void SetPosition (const Vector2& position);
      virtual void SetSize (const Vector2& size);
      /// @}

      /// @name ISpatial3 members.
      /// @{
      virtual const int& GetZ () const;
      virtual void SetZ (int z);

      virtual const int& GetH () const;
      virtual void SetH (int h);
      /// @}

      /// @name ICollidable members.
      /// @{
      virtual bool CollidesWith (const ICollidable& other) const;
      virtual bool CollidesWith (
        const ICollidable& other,
        const Vector2& offset) const;
      /// @}

    protected:

      BoundingBoxCollection ();

      BoundingBoxCollection (const BoundingBoxCollection& copy);

      void AddBoundingBox (BoundingBox* boundingBox);
      void RemoveBoundingBox (BoundingBox* boundingBox);

      CollidableArea& GetCollidableArea ();
      void SetCollidableArea (CollidableArea* collidableArea);

      const collection::List<BoundingBox*>& GetBoundingBoxes () const;

    private:

      void AddBoundingBoxToCollidableArea (BoundingBox* boundingBox);
      void RemoveBoundingBoxFromCollidableArea (BoundingBox* boundingBox);

      virtual void HandleAddBoundingBoxToCollidableArea (
        BoundingBox* boundingBox) = 0;
      virtual void HandleRemoveBoundingBoxFromCollidableArea (
        BoundingBox* boundingBox) = 0;

      void AddBoundingBoxesToCollidableArea ();
      void RemoveBoundingBoxesFromCollidableArea ();

      Spatial3Info spatial3Info_;

      collection::List<BoundingBox*> boundingBoxes_;

      CollidableArea* collidableArea_;
  };
} // namespace yap

#endif // YAPOG_BOUNDINGBOXCOLLECTION_HPP
