#include "YAPOG/Game/World/Map/TriggerBattleMapEventAction.hpp"
#include "YAPOG/Game/World/Map/BattleSpawnerArea.hpp"
#include "YAPOG/Game/World/Map/MapEventArgs.hpp"
#include "YAPOG/Game/World/Map/IPlayer.hpp"
#include "YAPOG/System/StringHelper.hpp"
#include "YAPOG/System/RandomHelper.hpp"

#include "YAPOG/Log.hpp"
namespace yap
{
  const String TriggerBattleMapEventAction::OBJECT_ENTERING_HANDLER_NAME =
    "ObjectEntering";

  TriggerBattleMapEventAction::TriggerBattleMapEventAction (
    BattleSpawnerArea& source)
    : BaseMapEventAction ()
    , source_ (source)
  {
  }

  TriggerBattleMapEventAction::~TriggerBattleMapEventAction ()
  {
  }

  TriggerBattleMapEventAction::TriggerBattleMapEventAction (
    const TriggerBattleMapEventAction& copy)
    : BaseMapEventAction (copy)
    , source_ (copy.source_)
  {
  }

  TriggerBattleMapEventAction* TriggerBattleMapEventAction::Clone () const
  {
    return new TriggerBattleMapEventAction (*this);
  }

  void TriggerBattleMapEventAction::VisitPlayer (IPlayer& visitable)
  {
    yap::BaseMapEventAction::VisitPlayer (visitable);

    switch (GetContextType ())
    {
      case MapEventActionType::Enter:

        visitable.OnMovedEvent ().AddHandler (
          OBJECT_ENTERING_HANDLER_NAME +
          yap::StringHelper::ToString (
            source_.GetWorldID ().GetValue ()),
          [&] (
            DynamicWorldObject& sender,
            const Vector2& args)
          {
            if (!TriggerBattle (args))
              return false;

            GetArgs ().AbortEvents ();
            visitable.TriggerBattle ();

            return true;
          });

        break;

      case MapEventActionType::In:

        break;

      case MapEventActionType::Leave:

        visitable.OnMovedEvent ().RemoveHandler (
          OBJECT_ENTERING_HANDLER_NAME +
          yap::StringHelper::ToString (
            source_.GetWorldID ().GetValue ()));

        break;

      default: break;
    }
  }

  const int BATTLE_TRIGGERING_RANDOM_RANGE = 2550;
  const int BATTLE_TRIGGERING_RANDOM_DRANGE = 400;
  bool TriggerBattleMapEventAction::TriggerBattle (const Vector2& offset)
  {
    int dRange = RandomHelper::GetNext (1, BATTLE_TRIGGERING_RANDOM_DRANGE);
    int range = RandomHelper::GetNext (1, BATTLE_TRIGGERING_RANDOM_RANGE);

    int gRange = range + dRange;

    gRange *= offset.x + offset.y;

    return
      RandomHelper::GetNext (1, gRange) ==
      RandomHelper::GetNext (1, gRange);
  }
} // namespace yap
