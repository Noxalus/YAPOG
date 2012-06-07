#ifndef YAPOG_MAPEVENTCONTEXTTRIGGERCOMPARATOR_HPP
# define YAPOG_MAPEVENTCONTEXTTRIGGERCOMPARATOR_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/LessComparator.hpp"

namespace yap
{
  class MapEventContext;

  class YAPOG_LIB MapEventContextTriggerComparator
    : public LessComparator<MapEventContext*>
  {
    public:

      MapEventContextTriggerComparator ();
      virtual ~MapEventContextTriggerComparator ();

      MapEventContextTriggerComparator (
        const MapEventContextTriggerComparator& copy);
      MapEventContextTriggerComparator& operator= (
        const MapEventContextTriggerComparator& copy);

    protected:

      virtual int HandleCompare (
        MapEventContext* const& left,
        MapEventContext* const& right) const;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTCONTEXTTRIGGERCOMPARATOR_HPP
