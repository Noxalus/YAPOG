#ifndef YAPOG_WORLDOBJECTACTIONCOLLECTION_HPP
# define YAPOG_WORLDOBJECTACTIONCOLLECTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Collection/Map.hpp"

namespace yap
{
  struct IWorldObjectAction;

  class WorldObjectActionCollection
  {
      DISALLOW_COPY(WorldObjectActionCollection);

    public:

      WorldObjectActionCollection ();
      ~WorldObjectActionCollection ();

      void AddAction (const String& name, IWorldObjectAction* action);
      void RemoveAction (const String& name);

      void PerformAction (const String& name);

    private:

      typedef collection::Map<String, IWorldObjectAction*> ActionMap;

      ActionMap actions_;
  };
} // namespace yap

#endif // YAPOG_WORLDOBJECTACTIONCOLLECTION_HPP
