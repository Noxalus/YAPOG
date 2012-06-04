#include "YAPOG/Game/Battle/Battle.hpp"
#include "YAPOG/Game/Battle/BattleCore.hpp"
#include "YAPOG/Game/Battle/PokemonFighter.hpp"
#include "YAPOG/Game/Battle/PokemonFighterTeam.hpp"

namespace yap
{
  Battle::Battle ()
    : playerTeam_ (nullptr)
    , opponent_ (nullptr)
    , turnCount_ (0)
    , battlePhaseManager_ ()
  {
  }

  /// Setters
  void Battle::SetPlayerTeam (PokemonFighterTeam* playerTeam)
  {
    playerTeam_ = playerTeam;
  }

  void Battle::SetOpponent (PokemonFighterTeam* opponent)
  {
    opponent_ = opponent;
  }

  void Battle::SetOpponent (PokemonFighter* opponent)
  {
    opponent_ = opponent;
  }

  void Battle::Init ()
  {
    battlePhaseManager_.SetBattle (this);
    HandleInit ();
  }

  void Battle::HandleInit ()
  {
  }

  void Battle::AddPhase (
    const BattlePhaseState& battlePhaseState, 
    BattlePhase* battlePhase)
  {
    battlePhaseManager_.AddPhase (battlePhaseState, battlePhase);
  }

  void Battle::Update (const Time& dt)
  {
    HandleUpdate (dt);
    battlePhaseManager_.Update (dt);
  }

  void Battle::HandleUpdate (const Time& dt)
  {
  }

  void Battle::DisplayMoves ()
  {
  }

  void Battle::DisplayTeam ()
  {
  }

  IBattleEntity& Battle::GetPlayerTeam ()
  { return *playerTeam_; }

  IBattleEntity& Battle::GetOpponent ()
  { return *opponent_; }
} // namespace yap
