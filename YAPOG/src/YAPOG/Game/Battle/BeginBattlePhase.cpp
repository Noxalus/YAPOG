# include "YAPOG/Game/Battle/BeginBattlePhase.hpp"

namespace yap
{
  BeginBattlePhase::BeginBattlePhase ()
  {
  }

  void BeginBattlePhase::HandleStart ()
  {
    BattlePhase::HandleStart ();
    std::cout << "BEGIN !" << std::endl;
  }

  void BeginBattlePhase::HandleEnd ()
  {
    BattlePhase::HandleEnd ();
    std::cout << "FIGHT !" << std::endl;
  }
}