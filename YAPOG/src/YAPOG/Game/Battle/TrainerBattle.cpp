#include "YAPOG/Game/Battle/TrainerBattle.hpp"

namespace yap
{
  TrainerBattle::TrainerBattle (
    IBattleEntity& playerTeam, 
    IBattleEntity& opponentTeam)
    : Battle (playerTeam, opponentTeam)
  {
  }

  void TrainerBattle::DisplayBeginMessage ()
  {
  }

} // namespace yap