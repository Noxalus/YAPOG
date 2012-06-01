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

    SetCurrentPhaseState (battlePhaseState);

    int i = 1;
    for (auto& bp : battlePhases_)
    {
      std::cout << "Element #" << i << std::endl;
      if (bp.first == BattlePhaseState::BeginBattle)
        std::cout << "BEGIN BATTLE !" << std::endl;
      if (bp.first == BattlePhaseState::Selection)
        std::cout << "SELECTION !" << std::endl;

      i++;
    }

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