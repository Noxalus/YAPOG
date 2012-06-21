#include "YAPOG/Game/Battle/Phase/BeginWildBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  BeginWildBattlePhase::BeginWildBattlePhase (Battle& battle)
    : BeginBattlePhase (battle)
  {
  }

   BeginWildBattlePhase::~BeginWildBattlePhase ()
   {
   }

  void BeginWildBattlePhase::HandleStart (PhaseArgs* args)
  {
    BattlePhase::HandleStart (args);
    std::cout << "BEGIN WILD BATTLE !" << std::endl;
  }

  void BeginWildBattlePhase::HandleUpdate (const Time& dt)
  {
    BattlePhase::HandleUpdate (dt);
  }

  void BeginWildBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "FIGHT AGAINST WILD POKEMON !" << std::endl;
  }
}