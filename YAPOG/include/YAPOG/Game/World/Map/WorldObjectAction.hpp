#ifndef YAPOG_WORLDOBJECTACTION_HPP
# define YAPOG_WORLDOBJECTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IWorldObjectAction.hpp"

namespace yap
{
  class DynamicWorldObject;

  class WorldObjectAction : public IWorldObjectAction
  {
      DISALLOW_COPY(WorldObjectAction);

    public:

      virtual ~WorldObjectAction ();

      /// @name IWorldObjectAction members.
      /// @{
      virtual void Perform ();
      /// @}

    protected:

      explicit WorldObjectAction (DynamicWorldObject& parent);

      virtual void HandlePerform ();

    private:

      DynamicWorldObject& parent_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTACTION_HPP
