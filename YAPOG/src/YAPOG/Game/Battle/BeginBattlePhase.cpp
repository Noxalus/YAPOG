# include "YAPOG/Game/Battle/BeginBattlePhase.hpp"

namespace yap
{
  BeginBattlePhase::BeginBattlePhase ()
    : BattlePhase (BattlePhaseState::BeginBattle)
  {
  }

   BeginBattlePhase::~BeginBattlePhase ()
   {
   }

  void BeginBattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN !" << std::endl;
  }

  void BeginBattlePhase::HandleUpdate (const Time& dt)
  {
    nextPhase_ = BattlePhaseState::BeginTurn;
  }

  void BeginBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "FIGHT !" << std::endl;
  }
}