#include "YAPOG/Game/World/Map/MapEventQueue.hpp"

namespace yap
{
  MapEventQueue::MapEventQueue ()
    : events_ ()
  {
  }

  void MapEventQueue::AddEvent (MapEventContext* event)
  {
    events_.Enqueue (event);
  }

  MapEventContext& MapEventQueue::GetEvent ()
  {
    MapEventContext* event = nullptr;

    return *events_.Dequeue (event);
  }

  bool MapEventQueue::IsEmpty () const
  {
    return events_.IsEmpty ();
  }
} // namespace yap
