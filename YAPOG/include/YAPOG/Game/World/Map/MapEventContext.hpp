#ifndef YAPOG_MAPEVENTCONTEXT_HPP
# define YAPOG_MAPEVENTCONTEXT_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class DynamicWorldObject;
  class ICollidable;
  class MapEventInfo;

  /// @brief Represents the triggering of an event with the trigger and its map
  /// context.
  class MapEventContext
  {
      DISALLOW_COPY(MapEventContext);

    public:

      MapEventContext (
        DynamicWorldObject& trigger,
        ICollidable& triggerCollidable,
        MapEventInfo& mapEventInfo);

      DynamicWorldObject& GetTrigger ();
      ICollidable& GetTriggerCollidable ();
      MapEventInfo& GetMapEventInfo ();

    private:

      DynamicWorldObject& trigger_;
      ICollidable& triggerCollidable_;
      MapEventInfo& mapEventInfo_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTCONTEXT_HPP
