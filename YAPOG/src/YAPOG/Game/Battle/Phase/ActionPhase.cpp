#include "YAPOG/Game/Battle/Phase/ActionPhase.hpp"

namespace yap
{
  ActionPhase::ActionPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Action)
    , playerIsFirst_ (true)
  {
  }

  void ActionPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN ACTION !" << std::endl;

    playerIsFirst_ = true;
  }

  void ActionPhase::HandleUpdate (const Time& dt)
  {
  }

  void ActionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END ACTION !" << std::endl;
  }
}