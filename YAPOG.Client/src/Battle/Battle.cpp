#include "Battle/Battle.hpp"
#include "YAPOG/Game/Battle/IBattleEntity.hpp"

namespace ycl
{
  Battle::Battle (
    yap::IBattleEntity& playerTeam, 
    yap::IBattleEntity& opponent)
    : yap::Battle (playerTeam, opponent)
  {
  }

  Battle::~Battle ()
  {
  }

} // namespace yap