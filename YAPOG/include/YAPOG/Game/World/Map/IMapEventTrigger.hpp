#ifndef YAPOG_IMAPEVENTTRIGGER_HPP
# define YAPOG_IMAPEVENTTRIGGER_HPP

namespace yap
{
  class CollidableArea;
  class MapEventQueue;

  struct IMapEventTrigger
  {
      virtual ~IMapEventTrigger () { }

      virtual void GetEventsCollidingWith (
        const CollidableArea& collidableArea,
        MapEventQueue& events) const = 0;
  };
} // namespace yap

#endif // YAPOG_IMAPEVENTTRIGGER_HPP
