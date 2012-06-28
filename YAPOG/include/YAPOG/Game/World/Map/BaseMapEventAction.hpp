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
      virtual bool Execute (DynamicWorldObject& trigger, MapEventArgs& args);

      virtual const MapEventActionType& GetType () const;
      /// @}

      /// @name IDynamicWorldObjectVisitor
      /// @{
      virtual void VisitCharacter (Character& visitable);
      virtual void VisitPlayer (IPlayer& visitable);
      virtual void VisitTeleporter (Teleporter& visitable);
      virtual void VisitDestructibleObject (DestructibleObject& visitable);
      virtual void VisitBattleSpawnerArea (BattleSpawnerArea& visitable);
      /// @}

    protected:

      explicit BaseMapEventAction (MapEventActionType type);

      BaseMapEventAction (const BaseMapEventAction& copy);

      MapEventArgs& GetArgs ();

    private:

      virtual bool HandleExecute (MapEventArgs& args);

      MapEventActionType type_;

      MapEventArgs* args_;
  };
} // namespace yap

#endif // YAPOG_BASEMAPEVENTACTION_HPP
