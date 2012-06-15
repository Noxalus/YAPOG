#include "YAPOG/Game/Battle/Phase/SelectionPhase.hpp"

namespace yap
{
  SelectionPhase::SelectionPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Selection)
  {
  }

  void SelectionPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN SELECTION !" << std::endl;
  }

  void SelectionPhase::HandleUpdate (const Time& dt)
  {
    BattlePhase::HandleUpdate (dt);
  }

  void SelectionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END SELECTION !" << std::endl;
  }
}