# include "YAPOG/Game/Battle/Phase/BeginTurnPhase.hpp"
# include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  BeginTurnPhase::BeginTurnPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::BeginTurn)
  {
  }

  void BeginTurnPhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN TURN !" << std::endl;
  }

  void BeginTurnPhase::HandleUpdate (const Time& dt)
  {
    yap::BattlePhase::SwitchPhase (BattlePhaseState::Selection);
  }

  void BeginTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END BEGIN TURN !" << std::endl;
  }
}