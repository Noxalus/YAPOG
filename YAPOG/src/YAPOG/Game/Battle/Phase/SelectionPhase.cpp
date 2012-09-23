#include "YAPOG/Game/Battle/Phase/SelectionPhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  SelectionPhase::SelectionPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Selection)
  {
  }

  void SelectionPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
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