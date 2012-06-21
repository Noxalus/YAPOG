#include "YAPOG/Game/Battle/Phase/EndTrainerBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  EndTrainerBattlePhase::EndTrainerBattlePhase (Battle& battle)
    : EndBattlePhase (battle)
  {
  }

  void EndTrainerBattlePhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN END TRAINER BATTLE PHASE !" << std::endl;
  }

  void EndTrainerBattlePhase::HandleUpdate (const Time& dt)
  {
    yap::BattlePhase::SwitchPhase (BattlePhaseState::BeginBattle);
  }

  void EndTrainerBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END END TRAINER BATTLE PHASE !" << std::endl;
  }
}