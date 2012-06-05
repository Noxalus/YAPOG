#ifndef YAPOG_MAPEVENTARGS_HPP
# define YAPOG_MAPEVENTARGS_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ICollidable;

  class Time;
  class DynamicWorldObject;
  class MapEventInfo;

  class MapEventArgs
  {
      DISALLOW_COPY(MapEventArgs);

    public:

      MapEventArgs (
        const Time& dt,
        DynamicWorldObject& trigger,
        ICollidable& triggerCollidable,
        MapEventInfo& mapContext);

      const Time& GetDt () const;

      DynamicWorldObject& GetTrigger ();
      ICollidable& GetTriggerCollidable ();

      MapEventInfo& GetMapContext ();

    private:

      const Time& dt_;

      DynamicWorldObject& trigger_;
      ICollidable& triggerCollidable_;

      MapEventInfo& mapContext_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTARGS_HPP
