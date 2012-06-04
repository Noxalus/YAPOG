#ifndef YAPOG_MAPEVENTINFO_HPP
# define YAPOG_MAPEVENTINFO_HPP

# include <memory>

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ICollidable;

  class MapEvent;
  class DynamicWorldObject;

  class MapEventInfo
  {
      DISALLOW_COPY(MapEventInfo);

    public:

      typedef std::shared_ptr<MapEventInfo> PtrType;

      MapEventInfo (
        const ICollidable& sourceCollidable,
        const MapEvent& event,
        const DynamicWorldObject& parent);

      const ICollidable& GetSourceCollidable () const;
      const MapEvent& GetEvent () const;
      const DynamicWorldObject& GetParent () const;

    private:

      const ICollidable& sourceCollidable_;
      const MapEvent& event_;
      const DynamicWorldObject& parent_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTINFO_HPP
