#ifndef YAPOG_MAPEVENTCONTEXT_HPP
# define YAPOG_MAPEVENTCONTEXT_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class ICollidable;
  class MapEventInfo;

  /// @brief Represents the triggering of an event with the trigger and its map
  /// context.
  class MapEventContext
  {
      DISALLOW_COPY(MapEventContext);

    public:

      MapEventContext (
        const ICollidable& triggerCollidable,
        const MapEventInfo& mapEventInfo);

      const ICollidable& GetTriggerCollidable () const;
      const MapEventInfo& GetMapEventInfo () const;

    private:

      const ICollidable& triggerCollidable_;
      const MapEventInfo& mapEventInfo_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTCONTEXT_HPP
