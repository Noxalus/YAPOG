# include "YAPOG/Game/Battle/Phase/BattlePhase.hpp"
# include "YAPOG/Game/Battle/Battle.hpp"
# include "YAPOG/Game/Battle/Phase/PhaseArgs.hpp"

namespace yap
{
  BattlePhase::BattlePhase (
    Battle& battle, 
    const BattlePhaseState& battlePhaseState)
    : state_ (battlePhaseState)
    , phaseArgs_ (nullptr)
    , battle_ (battle)
  {
  }

  PhaseArgs* BattlePhase::GetPhaseArgs ()
  {
    return phaseArgs_;
  }

  void BattlePhase::Start (PhaseArgs* args)
  {
    HandleStart (args);
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

  void BattlePhase::HandleStart (PhaseArgs* args)
  {
    if (args != nullptr)
      args->Accept (*this);
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

  void BattlePhase::SwitchPhase (BattlePhaseState nextPhase)
  {
    nextPhase_ = nextPhase;
    phaseArgs_ = nullptr;
  }

  void BattlePhase::SwitchPhase (BattlePhaseState nextPhase, PhaseArgs* args)
  {
    nextPhase_ = nextPhase;
    phaseArgs_ = args;
  }

  //Visitor's methods
  void BattlePhase::Visit (const ActionPhaseArgs& visitable)
  {
  }
}