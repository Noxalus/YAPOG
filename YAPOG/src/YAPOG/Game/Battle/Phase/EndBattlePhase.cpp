#include "YAPOG/Game/Battle/Phase/EndBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  EndBattlePhase::EndBattlePhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::EndBattle)
  {
  }

  void EndBattlePhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN END BATTLE PHASE !" << std::endl;
  }

  void EndBattlePhase::HandleUpdate (const Time& dt)
  {
  }

  void EndBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END END BATTLE PHASE !" << std::endl;
  }
}