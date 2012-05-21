#include "YAPOG/Game/Battle/Battle.hpp"
#include "YAPOG/Game/Battle/BattlePhaseManager.hpp"
#include "YAPOG/Game/Battle/BeginBattlePhase.hpp"
#include "YAPOG/Game/Battle/BeginTurnPhase.hpp"
#include "YAPOG/Game/Battle/SelectionPhase.hpp"
#include "YAPOG/Game/Battle/ActionPhase.hpp"
#include "YAPOG/Game/Battle/EndTurnPhase.hpp"
#include "YAPOG/Game/Battle/EndBattlePhase.hpp"

namespace yap
{
  const BattlePhaseState BattlePhaseManager::DEFAULT_BATTLE_PHASE 
    = BattlePhaseState::None;

  BattlePhaseManager::BattlePhaseManager (Battle& battle)
    : currentPhase_ (DEFAULT_BATTLE_PHASE)
    , battlePhases_ ()
    , battle_ (battle)
  {
    battlePhases_.Add (BattlePhaseState::BeginBattle, new BeginBattlePhase ());
    battlePhases_.Add (BattlePhaseState::BeginTurn, new BeginTurnPhase ());
    battlePhases_.Add (BattlePhaseState::Selection, new SelectionPhase ());
    //battlePhases_.Add (BattlePhaseState::Action, new ActionPhase ());
    battlePhases_.Add (BattlePhaseState::EndTurn, new EndTurnPhase ());
    battlePhases_.Add (BattlePhaseState::EndBattle, new EndBattlePhase ());

    currentPhase_ = BattlePhaseState::BeginBattle;
  }

  const BattlePhaseState& BattlePhaseManager::GetCurrentPhase () const
  {
    return currentPhase_;
  }

  void BattlePhaseManager::Update ()
  {
    battlePhases_[currentPhase_]->Update ();
  }
}