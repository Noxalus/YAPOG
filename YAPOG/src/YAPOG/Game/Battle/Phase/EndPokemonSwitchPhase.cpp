#include "YAPOG/Game/Battle/Phase/EndPokemonSwitchPhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  EndPokemonSwitchPhase::EndPokemonSwitchPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Switch)
  {
  }

  void EndPokemonSwitchPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN SWITCH !" << std::endl;
  }

  void EndPokemonSwitchPhase::HandleUpdate (const Time& dt)
  {
    BattlePhase::HandleUpdate (dt);
  }

  void EndPokemonSwitchPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END SWITCH !" << std::endl;
  }
}