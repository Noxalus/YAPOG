#include "YAPOG/Game/World/Map/MapEventContextTriggerComparator.hpp"
#include "YAPOG/Game/World/Map/MapEventContext.hpp"

namespace yap
{
  MapEventContextTriggerComparator::MapEventContextTriggerComparator ()
    : LessComparator<MapEventContext*> ()
  {
  }

  MapEventContextTriggerComparator::~MapEventContextTriggerComparator ()
  {
  }

  MapEventContextTriggerComparator::MapEventContextTriggerComparator (
    const MapEventContextTriggerComparator& copy)
    : LessComparator<MapEventContext*> (copy)
  {
  }

  MapEventContextTriggerComparator&
  MapEventContextTriggerComparator::operator= (
    const MapEventContextTriggerComparator& copy)
  {
    if (this == &copy)
      return *this;

    LessComparator<MapEventContext*>::operator= (copy);

    return *this;
  }

  int MapEventContextTriggerComparator::HandleCompare (
    MapEventContext* const& left,
    MapEventContext* const& right) const
  {
    return &left->GetTrigger () < &right->GetTrigger ();
  }
} // namespace yap
