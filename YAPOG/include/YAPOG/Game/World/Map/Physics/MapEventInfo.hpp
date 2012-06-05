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
        ICollidable& sourceCollidable,
        MapEvent& event,
        DynamicWorldObject& parent);

      ICollidable& GetSourceCollidable ();
      MapEvent& GetEvent ();
      DynamicWorldObject& GetParent ();

    private:

      ICollidable& sourceCollidable_;
      MapEvent& event_;
      DynamicWorldObject& parent_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTINFO_HPP
