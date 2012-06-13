#include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/BattlePhaseManager.hpp"
#include "YAPOG/Game/Battle/Phase/BeginBattlePhase.hpp"
#include "YAPOG/Game/Battle/Phase/BeginTurnPhase.hpp"
#include "YAPOG/Game/Battle/Phase/SelectionPhase.hpp"
#include "YAPOG/Game/Battle/Phase/ActionPhase.hpp"
#include "YAPOG/Game/Battle/Phase/EndTurnPhase.hpp"
#include "YAPOG/Game/Battle/Phase/EndBattlePhase.hpp"
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

    if (!battlePhases_.Contains (currentPhaseState_))
      YAPOG_THROW("This Battle doesn't contains this phase.");

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

    currentBattlePhase_->End ();
    
    BattlePhaseState previousState = currentPhaseState_;
    SetCurrentPhaseState (battlePhaseState);

    currentBattlePhase_->SetPreviousPhase (previousState);
    currentBattlePhase_->Start ();
  }

  void BattlePhaseManager::Update (const Time& dt)
  {
    if (battlePhases_.IsEmpty ())
      return;

    currentBattlePhase_->Update (dt);
    SwitchPhase (currentBattlePhase_->GetNext ());
  }

  void BattlePhaseManager::AddPhase (
    const BattlePhaseState& battlePhaseState, 
    BattlePhase* battlePhase)
  {
    bool wasEmpty = battlePhases_.IsEmpty ();
    battlePhases_.Add (battlePhaseState, battlePhase);

    if (wasEmpty)
    {
      SetCurrentPhaseState (battlePhaseState);
      currentBattlePhase_->Start ();
    }
  }
}