#include "YAPOG/Game/Battle/Phase/RunPhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  RunPhase::RunPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::Run)
  {
  }

  void RunPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN END RUN PHASE !" << std::endl;
  }

  void RunPhase::HandleUpdate (const Time& dt)
  {
  }

  void RunPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END END RUN PHASE !" << std::endl;
  }
}