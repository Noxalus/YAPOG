#include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Game/Battle/BattlePhase.hpp"
#include "YAPOG/Game/Battle/BattlePhaseManager.hpp"
#include "YAPOG/Game/Battle/BeginBattlePhase.hpp"
#include "YAPOG/Game/Battle/BeginTurnPhase.hpp"
#include "YAPOG/Game/Battle/SelectionPhase.hpp"
#include "YAPOG/Game/Battle/ActionPhase.hpp"
#include "YAPOG/Game/Battle/EndTurnPhase.hpp"
#include "YAPOG/Game/Battle/EndBattlePhase.hpp"
#include "YAPOG/System/Error/Exception.hpp"
#include "YAPOG/System/StringHelper.hpp"

namespace yap
{
  const BattlePhaseState BattlePhaseManager::DEFAULT_BATTLE_PHASE 
    = BattlePhaseState::BeginBattle;

  BattlePhaseManager::BattlePhaseManager ()
    : battle_ (nullptr)
    , currentPhaseState_ (DEFAULT_BATTLE_PHASE)
    , currentBattlePhase_ (nullptr)
    , battlePhases_ ()
  {
  }

  void BattlePhaseManager::SetCurrentPhaseState (
    const BattlePhaseState& battlePhaseState)
  {
    currentPhaseState_ = battlePhaseState;
    currentBattlePhase_ = battlePhases_[currentPhaseState_];
  }

  const BattlePhaseState& BattlePhaseManager::GetCurrentPhaseState () const
  {
    return currentPhaseState_;
  }

  void BattlePhaseManager::SetBattle (Battle* battle)
  {
    battle_ = battle;
  }

  void BattlePhaseManager::SwitchPhase (
    const BattlePhaseState& battlePhaseState)
  {
    if (currentPhaseState_ == battlePhaseState)
      return;

    if (!battlePhases_.Contains (currentPhaseState_))
      YAPOG_THROW("This Battle doesn't have this state.");

    currentBattlePhase_->End ();

    SetCurrentPhaseState (battlePhaseState);
    currentBattlePhase_->Start ();
  }

  void BattlePhaseManager::Update (const Time& dt)
  {
    if (battlePhases_.IsEmpty ())
      return;

    currentBattlePhase_->Update (dt);
  }

  void BattlePhaseManager::AddPhase (
    const BattlePhaseState& battlePhaseState, 
    BattlePhase* battlePhase)
  {
    battlePhase->SetBattle (battle_);

    bool wasEmpty = battlePhases_.IsEmpty ();
    battlePhases_.Add (battlePhaseState, battlePhase);

    if (wasEmpty)
    {
      SetCurrentPhaseState (battlePhaseState);
      currentBattlePhase_->Start ();
    }
  }
}