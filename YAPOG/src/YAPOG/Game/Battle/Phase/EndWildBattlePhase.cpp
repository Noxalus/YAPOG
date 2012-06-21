#include "YAPOG/Game/Battle/Phase/EndWildBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  EndWildBattlePhase::EndWildBattlePhase (Battle& battle)
    : EndBattlePhase (battle)
  {
  }

  void EndWildBattlePhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN END WILD BATTLE PHASE !" << std::endl;
  }

  void EndWildBattlePhase::HandleUpdate (const Time& dt)
  {
    yap::BattlePhase::SwitchPhase (BattlePhaseState::BeginBattle);
  }

  void EndWildBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END END WILD BATTLE PHASE !" << std::endl;
  }
}