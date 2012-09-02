#ifndef YAPOG_IMAPEVENTACTION_HPP
# define YAPOG_IMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/Factory/ICloneable.hpp"
# include "YAPOG/Game/World/Map/IDynamicWorldObjectVisitor.hpp"
# include "YAPOG/Game/World/Map/MapEventActionType.hpp"

namespace yap
{
  class DynamicWorldObject;
  class MapEventArgs;

  struct IMapEventAction : public ICloneable
                         , public IDynamicWorldObjectVisitor
  {
      virtual ~IMapEventAction () { }

      /// @brief Sets up the MapEventArgs @a args for the next execution.
      /// @param trigger DynamicWorldObject @a trigger that triggered this
      /// IMapEventAction.
      /// @param args Arguments that hold the context of the triggering of
      /// this IMapEventAction.
      /// @return False if conditions are not fulfilled or if the execution
      /// fails.
      virtual bool Execute (
        MapEventActionType contextType,
        DynamicWorldObject& trigger,
        MapEventArgs& args) = 0;

      virtual IMapEventAction* Clone () const { return nullptr; }
  };
} // namespace yap

#endif // YAPOG_IMAPEVENTACTION_HPP
