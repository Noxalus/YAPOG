#include "YAPOG/Game/Battle/Phase/BeginBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  BeginBattlePhase::BeginBattlePhase (Battle& battle)
    : BattlePhase (battle, BattlePhaseState::BeginBattle)
  {
  }

   BeginBattlePhase::~BeginBattlePhase ()
   {
   }

  void BeginBattlePhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
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