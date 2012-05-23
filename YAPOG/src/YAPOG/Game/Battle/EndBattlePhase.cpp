# include "YAPOG/Game/Battle/EndBattlePhase.hpp"

namespace yap
{
  EndBattlePhase::EndBattlePhase ()
    : BattlePhase (BattlePhaseState::EndBattle)
  {
  }

  void EndBattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN END BATTLE PHASE !" << std::endl;
  }

  void EndBattlePhase::HandleUpdate (const Time& dt)
  {
    nextPhase_ = BattlePhaseState::BeginBattle;
  }

  void EndBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "END END BATTLE PHASE !" << std::endl;
  }
}