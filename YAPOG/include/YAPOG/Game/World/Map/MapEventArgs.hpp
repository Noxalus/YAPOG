#ifndef YAPOG_MAPEVENTARGS_HPP
# define YAPOG_MAPEVENTARGS_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ICollidable;

  class Time;
  class DynamicWorldObject;
  class MapEventInfo;

  class YAPOG_LIB MapEventArgs
  {
      DISALLOW_COPY(MapEventArgs);

    public:

      MapEventArgs (
        const Time& dt,
        DynamicWorldObject& trigger,
        const ICollidable& triggerCollidable,
        MapEventInfo& mapContext);

      const Time& GetDt () const;

      DynamicWorldObject& GetTrigger ();
      const ICollidable& GetTriggerCollidable () const;

      MapEventInfo& GetMapContext ();

    private:

      const Time& dt_;

      DynamicWorldObject& trigger_;
      const ICollidable& triggerCollidable_;

      MapEventInfo& mapContext_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTARGS_HPP
