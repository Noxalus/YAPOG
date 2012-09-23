# include "YAPOG/Game/Battle/Phase/BeginTurnPhase.hpp"
# include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  BeginTurnPhase::BeginTurnPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::BeginTurn)
  {
  }

  void BeginTurnPhase::HandleStart (const PhaseArgs& args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN TURN !" << std::endl;
  }

  void BeginTurnPhase::HandleUpdate (const Time& dt)
  {
  }

  void BeginTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END BEGIN TURN !" << std::endl;
  }
}