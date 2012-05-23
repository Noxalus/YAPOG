#include "YAPOG/Game/Battle/WildBattle.hpp"

namespace yap
{
  WildBattle::WildBattle (
    IBattleEntity& playerTeam, 
    IBattleEntity& wildPokemon)
    : Battle (playerTeam, wildPokemon)
  {
  }

  WildBattle::~WildBattle ()
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();
  }

  void WildBattle::HandleUpdate (const Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

} // namespace yap