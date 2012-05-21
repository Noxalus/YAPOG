#include "YAPOG/Game/Battle/WildBattle.hpp"
#include "YAPOG/Game/Pokemon/PokemonSkill.hpp"
#include "YAPOG/Game/Battle/BeginBattlePhase.hpp"

using namespace std;

namespace yap
{
  WildBattle::WildBattle (
    IBattleEntity& playerTeam, 
    IBattleEntity& wildPokemon)
    : Battle (playerTeam, wildPokemon)
  {
  }

  void WildBattle::HandleInit ()
  {
    Battle::HandleInit ();

    BeginBattlePhase* beginBattlePhase = new BeginBattlePhase ();

    AddPhase (BattlePhaseState::BeginBattle, beginBattlePhase);
  }

  void WildBattle::HandleUpdate (const Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

} // namespace yap