#ifndef YAPOG_MAPCOLLIDABLEINFO_HPP
# define YAPOG_MAPCOLLIDABLEINFO_HPP

# include <memory>

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ICollidable;

  class WorldObject;

  class MapCollidableInfo
  {
      DISALLOW_COPY(MapCollidableInfo);

    public:

      typedef std::shared_ptr<MapCollidableInfo> PtrType;

      MapCollidableInfo (
        const ICollidable& collidable,
        const WorldObject& parent);

      const ICollidable& GetCollidable () const;
      const WorldObject& GetParent () const;

    private:

      const ICollidable& collidable_;
      const WorldObject& parent_;
  };
} // namespace yap

#endif // YAPOG_MAPCOLLIDABLEINFO_HPP
