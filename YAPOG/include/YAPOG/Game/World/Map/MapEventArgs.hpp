#ifndef YAPOG_MAPEVENTARGS_HPP
# define YAPOG_MAPEVENTARGS_HPP

# include "YAPOG/Macros.hpp"

namespace yap
{
  struct ICollidable;

  class DynamicWorldObject;
  class MapEventInfo;

  /// @todo
  class MapEventArgs
  {
      DISALLOW_COPY(MapEventArgs);

    public:

      MapEventArgs (
        const ICollidable& sourceCollidable,
        const ICollidable& triggerCollidable,
        const DynamicWorldObject& source,
        const DynamicWorldObject& trigger,
        const MapEventInfo& context);

    private:

      /// @warning Temporary constness.

      const ICollidable& sourceCollidable_;
      const ICollidable& triggerCollidable_;

      const DynamicWorldObject& source_;
      const DynamicWorldObject& trigger_;

      const MapEventInfo& context_;
  };
} // namespace yap

#endif // YAPOG_MAPEVENTARGS_HPP
