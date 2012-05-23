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

      void SetSize (const Vector2& size);

    protected:

      virtual void HandleSetSize (uint width, uint height);

      virtual void HandleAddCollidable (ICollidable* collidable);

    private:

      static const Vector2 DEFAULT_SIZE;
      static const Vector2 DEFAULT_CELL_SIZE;

      Vector2 size_;
      Vector2 cellSize_;

      collection::Matrix<CollidableAreaCell*> cells_;
  };
} // namespace yap

#endif // YAPOG_GRIDCOLLIDABLEAREA_HPP
