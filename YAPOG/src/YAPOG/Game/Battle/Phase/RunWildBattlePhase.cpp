#include "YAPOG/Game/Battle/Phase/RunWildBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  RunWildBattlePhase::RunWildBattlePhase (Battle& battle)
    : RunPhase (battle)
  {
  }

  void RunWildBattlePhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN RUN WILD BATTLE PHASE !" << std::endl;
  }

  void RunWildBattlePhase::HandleUpdate (const Time& dt)
  {
  }

  void RunWildBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END RUN WILD BATTLE PHASE !" << std::endl;
  }
}