#ifndef YAPOG_TRIGGERBATTLEMAPEVENTACTION_HPP
# define YAPOG_TRIGGERBATTLEMAPEVENTACTION_HPP

# include "YAPOG/Macros.hpp"
# include "YAPOG/Game/World/Map/BaseMapEventAction.hpp"
# include "YAPOG/System/String.hpp"
# include "YAPOG/Graphics/Vector2.hpp"

namespace yap
{
  class BattleSpawnerArea;

  class TriggerBattleMapEventAction : public BaseMapEventAction
  {
      DISALLOW_ASSIGN(TriggerBattleMapEventAction);

    public:

      explicit TriggerBattleMapEventAction (
        MapEventActionType type,
        BattleSpawnerArea& source);
      virtual ~TriggerBattleMapEventAction ();

      virtual void VisitPlayer (IPlayer& visitable);

      /// @name ICloneable members.
      /// @{
      virtual TriggerBattleMapEventAction* Clone () const;
      /// @}

    protected:

      TriggerBattleMapEventAction (const TriggerBattleMapEventAction& copy);

    private:

      static const String OBJECT_ENTERING_HANDLER_NAME;

      bool TriggerBattle (const Vector2& offset);

      BattleSpawnerArea& source_;
  };
} // namespace yap

#endif // YAPOG_TRIGGERBATTLEMAPEVENTACTION_HPP
