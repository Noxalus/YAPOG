#include "YAPOG/Game/Battle/WildBattle.hpp"
#include "YAPOG/Game/Pokemon/PokemonSkill.hpp"
#include "YAPOG/Game/Battle/BeginBattlePhase.hpp"
#include "YAPOG/Game/Battle/BeginTurnPhase.hpp"
#include "YAPOG/Game/Battle/SelectionPhase.hpp"
#include "YAPOG/Game/Battle/ActionPhase.hpp"
#include "YAPOG/Game/Battle/EndTurnPhase.hpp"
#include "YAPOG/Game/Battle/EndBattlePhase.hpp"

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
    BeginTurnPhase* beginTurnPhase = new BeginTurnPhase ();

    AddPhase (BattlePhaseState::BeginBattle, beginBattlePhase);
    AddPhase (BattlePhaseState::BeginTurn, beginTurnPhase);
  }

  void WildBattle::HandleUpdate (const Time& dt)
  {
    Battle::HandleUpdate (dt);
  }

} // namespace yap