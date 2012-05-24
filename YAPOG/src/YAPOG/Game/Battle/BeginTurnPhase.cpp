# include "YAPOG/Game/Battle/BeginTurnPhase.hpp"

namespace yap
{
  BeginTurnPhase::BeginTurnPhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::BeginTurn)
  {
  }

  void BeginTurnPhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN TURN !" << std::endl;
  }

  void BeginTurnPhase::HandleUpdate (const Time& dt)
  {
    nextPhase_ = BattlePhaseState::Selection;
  }

  void BeginTurnPhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END BEGIN TURN !" << std::endl;
  }
}