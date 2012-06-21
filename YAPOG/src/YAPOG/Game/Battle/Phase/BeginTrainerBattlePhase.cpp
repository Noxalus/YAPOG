#include "YAPOG/Game/Battle/Phase/BeginTrainerBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  BeginTrainerBattlePhase::BeginTrainerBattlePhase (Battle& battle)
    : BeginBattlePhase (battle)
  {
  }

   BeginTrainerBattlePhase::~BeginTrainerBattlePhase ()
   {
   }

  void BeginTrainerBattlePhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN TRAINER BATTLE !" << std::endl;
  }

  void BeginTrainerBattlePhase::HandleUpdate (const Time& dt)
  {
    BattlePhase::HandleUpdate (dt);
  }

  void BeginTrainerBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "FIGHT AGAINST TRAINER !" << std::endl;
  }
}