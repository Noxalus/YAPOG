#include "YAPOG/Game/Battle/Phase/EndTurnPhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  EndTurnPhase::EndTurnPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::EndTurn)
  {
  }

  void EndTurnPhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN END TURN PHASE !" << std::endl;
  }

  void EndTurnPhase::HandleUpdate (const Time& dt)
  {
    yap::BattlePhase::SwitchPhase (BattlePhaseState::EndBattle);
  }

  void EndTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END END TURN PHASE !" << std::endl;
  }
}