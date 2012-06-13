# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"

namespace yap
{
  BattlePhase::BattlePhase (
    Battle& battle, 
    const BattlePhaseState& battlePhaseState)
    : state_ (battlePhaseState)
    , battle_ (battle)
  {
  }

  void BattlePhase::Start ()
  {
    HandleStart ();
  }

  void BattlePhase::End ()
  {
    HandleEnd ();
  }

  void BattlePhase::Update (const Time& dt)
  {
    nextPhase_ = state_; 
    HandleUpdate (dt);
  }

  void BattlePhase::HandleStart ()
  {
  }

  void BattlePhase::HandleEnd ()
  {
  }

  void BattlePhase::HandleUpdate (const Time& dt)
  {
  }

  Battle& BattlePhase::GetBattle ()
  {
    return battle_;
  }

  const BattlePhaseState& BattlePhase::GetNext () const
  {
    return nextPhase_;
  }

  void BattlePhase::SetPreviousPhase (const BattlePhaseState& value)
  { previousPhase_ = value; }
}