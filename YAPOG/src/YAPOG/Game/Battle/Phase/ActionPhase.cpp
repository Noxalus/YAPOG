#include "YAPOG/Game/Battle/Phase/ActionPhase.hpp"

namespace yap
{
  ActionPhase::ActionPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Action)
  {
  }

  void ActionPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN ACTION !" << std::endl;
  }

  void ActionPhase::HandleUpdate (const Time& dt)
  {
    nextPhase_ = BattlePhaseState::EndTurn;
  }

  void ActionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END ACTION !" << std::endl;
  }
}