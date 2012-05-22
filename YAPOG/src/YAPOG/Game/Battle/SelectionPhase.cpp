#include "YAPOG/Game/Battle/SelectionPhase.hpp"

namespace yap
{
  SelectionPhase::SelectionPhase ()
    : BattlePhase (BattlePhaseState::Selection)
  {
  }

  void SelectionPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN SELECTION !" << std::endl;
  }

  void SelectionPhase::HandleUpdate (const Time& dt)
  {
    nextPhase_ = BattlePhaseState::Action;
  }

  void SelectionPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END SELECTION !" << std::endl;
  }
}