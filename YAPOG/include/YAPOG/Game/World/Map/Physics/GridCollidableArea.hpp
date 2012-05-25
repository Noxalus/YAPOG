#ifndef YAPOG_GRIDCOLLIDABLEAREA_HPP
# define YAPOG_GRIDCOLLIDABLEAREA_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/Physics/CollidableArea.hpp"
# include "YAPOG/Collection/Matrix.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class CollidableAreaCell;

  class GridCollidableArea : public CollidableArea
  {
      DISALLOW_COPY(GridCollidableArea);

    public:

      GridCollidableArea ();
      virtual ~GridCollidableArea ();

      void SetSegmentCount (uint vSegmentCount, uint hSegmentCount);

      virtual bool CollidesWith (const ICollidable& collidable) const;

    protected:

      virtual void HandleSetSize (const Vector2& size);

      virtual void HandleAddCollidable (ICollidable* collidable);
      virtual void HandleRemoveCollidable (ICollidable* collidable);

    private:

      void GetCollidableRectangle (
        const ICollidable& collidable,
        UIntRect& rectangle) const;

      static const uint MIN_VSEGMENT_COUNT;
      static const uint MIN_HSEGMENT_COUNT;

      uint vSegmentCount_;
      uint hSegmentCount_;

      Vector2 cellSize_;

      collection::Matrix<CollidableAreaCell*> cells_;
  };
} // namespace yap

#endif // YAPOG_GRIDCOLLIDABLEAREA_HPP
