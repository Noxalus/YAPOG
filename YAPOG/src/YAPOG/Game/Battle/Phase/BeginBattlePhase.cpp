# include "YAPOG/Game/Battle/Phase/BeginBattlePhase.hpp"

namespace yap
{
  BeginBattlePhase::BeginBattlePhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::BeginBattle)
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
    BattlePhase::HandleUpdate (dt);
  }

  void BeginBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "FIGHT !" << std::endl;
  }
}