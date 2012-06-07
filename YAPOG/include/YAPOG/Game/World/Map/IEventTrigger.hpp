#ifndef YAPOG_IEVENTTRIGGER_HPP
# define YAPOG_IEVENTTRIGGER_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  class CollidableArea;
  class MapEventQueue;

  struct IEventTrigger
  {
      virtual ~IEventTrigger () { }

      virtual void GetEventsCollidingWith (
        const CollidableArea& collidableArea,
        MapEventQueue& events) const = 0;
  };
} // namespace yap

#endif // YAPOG_IEVENTTRIGGER_HPP
