#include "YAPOG/Game/Battle/Phase/SwitchPhase.hpp"

namespace yap
{
  SwitchPhase::SwitchPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Switch)
  {
  }

  void SwitchPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN SWITCH !" << std::endl;
  }

  void SwitchPhase::HandleUpdate (const Time& dt)
  {
    BattlePhase::HandleUpdate (dt);
  }

  void SwitchPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END SWITCH !" << std::endl;
  }
}