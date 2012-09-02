#ifndef YAPOG_BASEMAPEVENTACTION_HPP
# define YAPOG_BASEMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/IMapEventAction.hpp"
# include "YAPOG/Game/World/Map/MapEventActionType.hpp"

namespace yap
{
  class YAPOG_LIB BaseMapEventAction : public IMapEventAction
  {
      DISALLOW_ASSIGN(BaseMapEventAction);

    public:

      virtual ~BaseMapEventAction ();

      /// @name IMapEventAction members.
      /// @{
      virtual bool Execute (
        MapEventActionType contextType,
        DynamicWorldObject& trigger,
        MapEventArgs& args);
      /// @}

      /// @name IDynamicWorldObjectVisitor
      /// @{
      virtual void VisitDynamicWorldObject (DynamicWorldObject& visitable);
      virtual void VisitCharacter (Character& visitable);
      virtual void VisitPlayer (IPlayer& visitable);
      virtual void VisitTeleporter (Teleporter& visitable);
      virtual void VisitDestructibleObject (DestructibleObject& visitable);
      virtual void VisitBattleSpawnerArea (BattleSpawnerArea& visitable);
      /// @}

    protected:

      BaseMapEventAction ();

      BaseMapEventAction (const BaseMapEventAction& copy);

      MapEventActionType GetContextType () const;

      MapEventArgs& GetArgs ();

    private:

      virtual bool HandleExecute (MapEventArgs& args);

      static const MapEventActionType DEFAULT_CONTEXT_TYPE;

      MapEventActionType contextType_;

      MapEventArgs* args_;
  };
} // namespace yap

#endif // YAPOG_BASEMAPEVENTACTION_HPP
